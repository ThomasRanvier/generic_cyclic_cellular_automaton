
const int WIDTH = 1350;
const int HEIGHT = 800;

const int CELL_SIZE = 3;

int RANGE, THRESHOLD, NB_STATES;
bool NEIGHBOUR_TYPE;//true : MOORE, false : NEUMANN

/*
const sf::Color COLORS[25] = {
        sf::Color(0x000000FF),
        sf::Color(0x032396FF),
        sf::Color(0x05569CFF),
        sf::Color(0x07709FFF),
        sf::Color(0x098BA2FF),
        sf::Color(0x0AA5A3FF),
        sf::Color(0x0CA88EFF),
        sf::Color(0x0EAB78FF),
        sf::Color(0x10AE62FF),
        sf::Color(0x12B14BFF),
        sf::Color(0x14B435FF),
        sf::Color(0x16B71EFF),
        sf::Color(0x29BA18FF),
        sf::Color(0x45BD1AFF),
        sf::Color(0x61C01CFF),
        sf::Color(0x7DC31EFF),
        sf::Color(0x9AC620FF),
        sf::Color(0xB6C923FF),
        sf::Color(0xCCC425FF),
        sf::Color(0xCFAC27FF),
        sf::Color(0xD2952AFF),
        sf::Color(0xD57E2DFF),
        sf::Color(0xD8662FFF),
        sf::Color(0xDB4E32FF),
        sf::Color(0xDE3735FF)};
*/
const sf::Color COLORS[25] = {
        sf::Color(0xD1390EFF),
        sf::Color(0xC96816FF),
        sf::Color(0xC08F1CFF),
        sf::Color(0xB7AF22FF),
        sf::Color(0x96AF27FF),
        sf::Color(0x72A62CFF),
        sf::Color(0x549D2FFF),
        sf::Color(0x3C9432FF),
        sf::Color(0x358C42FF),
        sf::Color(0x378354FF),
        sf::Color(0x387A61FF),
        sf::Color(0x38716AFF),
        sf::Color(0x386368FF),
        sf::Color(0x375160FF),
        sf::Color(0x354357FF),
        sf::Color(0x33374EFF),
        sf::Color(0x313046FF),
        sf::Color(0x312C3DFF),
        sf::Color(0x2F2834FF),
        sf::Color(0x2A232BFF),
        sf::Color(0x231D22FF),
        sf::Color(0x1A1719FF),
        sf::Color(0x111010FF),
        sf::Color(0x080808FF),
        sf::Color(0x000000FF)};
