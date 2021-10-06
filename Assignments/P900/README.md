## 900 - Brick Wall Patterns
### Austin Riddle
### Description:

If we want to build a brick wall out of the usual size of
brick which has a length twice as long as its height, and if
our wall is to be two units tall, we can make our wall in
a number of patterns, depending on how long we want it.
From the figure one observe that:
- There is just one wall pattern which is 1 unit wide —
made by putting the brick on its end.
- There are 2 patterns for a wall of length 2: two side-
ways bricks laid on top of each other and two bricks
long-ways up put next to each other.
- There are three patterns for walls of length 3.
How many patterns can you find for a wall of length 4? And, for a wall of length 5?

It turns out that the number of unique brick patterns corresponds to the Fibonacci sequence. Thus, the solution for n bricks is the simply the nth fibonacci number.

### Files


|   #   | File                       | Description                                                |
| :---: | -------------------------- | ---------------------------------------------------------- |
|   1   | [bricks.cpp](./bricks.cpp) | Solution Source Code.                                      |
|   2   | [brickdata.dat](./brickdata.dat) | Test input file from uDebug.                         |
|   3   | [900.pdf](./900.pdf)       | Original problem description document.                     |

### Instructions

- This project was compiled with GNU GCC 11.1.0.  It should work with any C++11 or newer compiler.
- Simply compile bricks.cpp and run the executable. ```g++ bricks.cpp -o bricks```
- To supply the input and output to a file, run it like this: ```./bricks < brickdata.dat > out.txt```

### Sources

- Math is Fun
    - https://www.mathsisfun.com/numbers/fibonacci-sequence.html

I used this to study the pattern of the Fibonacci Sequence so that I could write a program to recreate it.
