#include <iostream>
#include <SFML/Graphics.hpp>
#include "config.hpp"

const int NUMBER_OF_CELLS_X = WIDTH / CELL_SIZE;
const int NUMBER_OF_CELLS_Y = HEIGHT / CELL_SIZE;

void draw(int *map, sf::RenderWindow *window, int *oldMap) {
    for (int i(0); i < NUMBER_OF_CELLS_X * NUMBER_OF_CELLS_Y; i++) {
        if (oldMap[i] != map[i]) {
            int x((i % NUMBER_OF_CELLS_X) * CELL_SIZE), y((i / NUMBER_OF_CELLS_X) * CELL_SIZE);
            sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
            cell.setPosition(x, y);
            cell.setFillColor(COLORS[map[i]]);
            (*window).draw(cell);
        }
    }
}

void mapcpy(int *mapDest, int *map) {
    for (int i = 0; i < NUMBER_OF_CELLS_X * NUMBER_OF_CELLS_Y; i++) {
        mapDest[i] = map[i];
    }
}

bool isNextState(int valueToTest, int testValue) {
    bool result;
    if (valueToTest == NB_STATES - 1) {
        result = (testValue == 0);
    } else {
        result = (valueToTest == testValue - 1);
    }
    return result;
}

int countNextStateMoore(int *map, int index) {
    int count(0);

    int y(index / NUMBER_OF_CELLS_X), x(index % NUMBER_OF_CELLS_X);

    for (int i(-RANGE); i <= RANGE; i++) {
        for (int j(-RANGE); j <= RANGE; j++) {
            int newX((x + i) < 0 ? NUMBER_OF_CELLS_X + (x + i) : x + i);
            int newY((y + j) < 0 ? NUMBER_OF_CELLS_Y + (y + j) : y + j);
            if (isNextState(map[index], map[newX + newY * NUMBER_OF_CELLS_X])) count++;
        }
    }

    return count;
}

int countNextStateVonNeumann(int *map, int index) {
    int count(0);

    int y(index / NUMBER_OF_CELLS_X), x(index % NUMBER_OF_CELLS_X);

    for (int i(-RANGE); i <= RANGE; i++) {
        for (int j(-RANGE); j <= RANGE; j++) {
            if (abs(i) + abs(j) <= RANGE && abs(i) + abs(j) > 0) {
                int newX((x + i) < 0 ? NUMBER_OF_CELLS_X + (x + i) : x + i);
                int newY((y + j) < 0 ? NUMBER_OF_CELLS_Y + (y + j) : y + j);
                if (isNextState(map[index], map[newX + newY * NUMBER_OF_CELLS_X])) count++;
            }
        }
    }

    return count;
}

int countNextStateNeighbours(int *map, int i) {
    int count(0);
    if (NEIGHBOUR_TYPE) {
        count = countNextStateMoore(map, i);
    } else {
        count = countNextStateVonNeumann(map, i);
    }
    return count;
}

void nextCellState(int *map, int i, int *mapDest) {
    if (map[i] >= NB_STATES - 1) {
        mapDest[i] = 0;
    } else {
        mapDest[i] = map[i] + 1;
    }
}


void nextMapStep(int *map, int *mapDest) {
    for (int i = 0; i < NUMBER_OF_CELLS_X * NUMBER_OF_CELLS_Y; i++) {
        int count(countNextStateNeighbours(map, i));

        if (count >= THRESHOLD) {
            nextCellState(map, i, mapDest);
        }
    }
}

void updateMap(int *map) {
    int temp[NUMBER_OF_CELLS_X * NUMBER_OF_CELLS_Y] = {0};
    mapcpy(temp, map);
    nextMapStep(map, temp);
    mapcpy(map, temp);
}

void initMap(int *map) {
    srand(time(NULL));

    for (int i = 0; i < NUMBER_OF_CELLS_X * NUMBER_OF_CELLS_Y; i++) {
        map[i] = rand() % NB_STATES;
    }
}

void getUserParameters() {RANGE = 2;
    std::cout << "Range (1-5) : ";
    std::cin >> RANGE;
    std::cout << "\nThreshold (1-25) : ";
    std::cin >> THRESHOLD;
    std::cout << "\nStates (1-25) : ";
    std::cin >> NB_STATES;
    std::cout << "\nNeighbourhood (1 : Moore, 0 : Von-Neumann) : ";
    std::cin >> NEIGHBOUR_TYPE;
}

int main() {
    getUserParameters();

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Generic cyclic cellular automaton", sf::Style::Fullscreen);

    int map[NUMBER_OF_CELLS_X * NUMBER_OF_CELLS_Y] = {0},
            oldMap[NUMBER_OF_CELLS_X * NUMBER_OF_CELLS_Y] = {0};


    initMap(map);

    clock_t timer;
    double timeToDisplay, timeToDraw, timeToUpdate;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        timer = clock();
        draw(map, &window, oldMap);
        timeToDraw = clock() - timer;

        mapcpy(oldMap, map);

        timer = clock();
        window.display();
        timeToDisplay = clock() - timer;

        timer = clock();
        updateMap(map);
        timeToUpdate = clock() - timer;

        std::cout << "timeToDraw : " << timeToDraw << ", timeToDisplay : "
                  << timeToDisplay << ", timeToUpdate : " << timeToUpdate << std::endl;
    }
    return 0;
}