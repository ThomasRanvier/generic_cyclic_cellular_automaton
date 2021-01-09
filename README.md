# Generic cyclic 2D cellular automaton

This is an implementation of a generic cyclic 2D cellular automaton.

When the program starts you can enter the rules of the automaton:
- The range
- The threshold (number of next state cells needed in the neighbourhood to upgrade the cell state)
- The number of states
- The type of neighbourhood: Moore or Von-Neumann

Here are some results obtained with different rules: 

Range: 1, Threshold: 1, States: 16, Neighbourhood: Neumann

![1_1_16_neumann](1_1_16_neumann.gif)

Range: 1, Threshold: 3, States: 3, Neighbourhood: Moore

![1_3_3_moore](1_3_3_moore.gif)

Range: 2, Threshold: 3, States: 14, Neighbourhood: Moore

![2_3_14_moore](2_3_14_moore.gif)

Range: 2, Threshold: 4, States: 9, Neighbourhood: Moore

![2_4_9_moore](2_4_9_moore.gif)

Range: 3, Threshold: 4, States: 5, Neighbourhood: Neumann

![3_4_5_neumann](3_4_5_neumann.gif)

Range: 3, Threshold: 5, States: 8, Neighbourhood: Moore

![3_5_8_moore](3_5_8_moore.gif)
