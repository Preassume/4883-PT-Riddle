## 10017 - The Never Ending Towers of Hanoi
### Austin Riddle
### Description:

In 1883, Edward Lucas invented, or perhaps reinvented, one of the most popular puzzles of all times
– the Tower of Hanoi, as he called it – which is still used today in many computer science textbooks
to demonstrate how to write a recursive algorithm or program. First of all, we will make a list of the
rules of the puzzle:
- There are three pegs: A, B and C.
- There are n disks. The number n is constant while working the puzzle.
- All disks are different in size.
- The disks are initially stacked on peg A so that they increase in size from the top to the bottom.
- The goal of the puzzle is to transfer the entire tower from the A peg to the peg C.
- One disk at a time can be moved from the top of a stack either to an empty peg or to a peg with
a larger disk than itself on the top of its stack.
Your job will be to write a program which will show a copy of the puzzle on the screen step by step,
as you move the disks around. This program has to solve the problem in an efficient way.
TIP: It is well known and rather easy to prove that the minimum number of moves needed to complete
the puzzle with n disks is 2n − 1.

### Files


|   #   | File                       | Description                                                |
| :---: | -------------------------- | ---------------------------------------------------------- |
|   1   | [towers.cpp](./towers.cpp) | Solution Source Code.                                      |
|   2   | [data.dat](./data.dat)     | Test input file from uDebug.                               |
|   3   | [10017.pdf](./10017.pdf)   | Original problem description document.                     |

### Instructions

- This project was compiled with GNU GCC 11.1.0.  It should work with any C++11 or newer compiler.
- Simply compile towers.cpp and run the executable. ```g++ towers.cpp -o towers```
- To supply the input and output to a file, run it like this: ```./towers < data.dat > out.txt```

### Sources

- Wikipedia
    - https://en.wikipedia.org/wiki/Towers_of_hanoi

- Geeks for Geeks
    - https://www.geeksforgeeks.org/c-program-for-tower-of-hanoi/

- Book
    - Competitive Programming Three page 390




