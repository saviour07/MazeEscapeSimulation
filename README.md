# MazeEscapeSimulation

This is a project to simulate the following puzzle (taken from: https://www.theguardian.com/science/2018/may/07/can-you-solve-it-im-a-mathematician-get-me-out-of-here)

Imagine you are in a 100x100 grid of squares.
The grid is fixed to the compass directions: up/down is N/S, and left/right is W/E.
On each square of the grid there’s an arrow, where each arrow is pointing either N, S, W or E.
Choose any square and that’s your starting position.

The rules are:

* You must always follow the arrow
  * If the arrow in the starting square points N, then you move to the square due north. If the arrow points E, you move to the square due east.
* Once you arrive in a new square, then you must rotate the arrow in the previous square by 90 degrees clockwise
  * If the previous square pointed N, then once you leave that square you must rotate that arrow to E. If the previous square pointed E, once you leave that square you must rotate that arrow to S.
* You can only escape the grid if you are on an edge square where the arrow is pointing in the direction beyond the maze
  * If you are in a square on the top edge and the arrow points N, then the following move you are going to get out the grid. If you are on the bottom edge and the arrow points S, then the following move you are going to get out the grid.

Here’s the puzzle's statement:

“No matter which directions the arrows are pointing at the start, and no matter which square you choose to begin, you will always eventually get OUT OF THE GRID”

True or false?
