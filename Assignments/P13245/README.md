## 13245 - Prime Darts
### Austin Riddle
### Description:

A dartboard manufacturer wants to revolutionize the
game of darts, creating a prime dartboard for math geeks.
He has designed several boards with different numbers of
areas, so that a board with n areas has the following scores:
the first area is worth 1 point, the remaining n − 1 areas
have a value corresponding to the first n−1 prime numbers.
For example, a prime dartboard with 20 areas could be
as in the picture on the right:
We want to know the minimum number of darts needed
to obtain a score of q points on a prime dartboard of size
n.

### Files


|   #   | File                                | Description                              |
| :---: | ----------------------------------- | ---------------------------------------- |
|   1   |[dart-greedy.cpp](./dart-greedy.cpp) | Solution source code.                    |
|   2   |[dart-tree.cpp](./dart-tree.cpp) | Solution source code.                    |
|   3   |[data.dat](./data.dat)               | Test input file from uDebug.             |
|   4   |[13245.pdf](./13245.pdf)       | Original problem description document.   |

### Instructions

- This project was compiled with GNU GCC 11.1.0.  It should work with any C++11 or newer compiler.
- Simply compile d.cpp and run the executable. ```g++ dart-tree.cpp -o dart-tree```
- To supply the input file, run it like this: ```./dart-tree < data.dat```
- To output to a file, run it like this: ```./dart-tree < data.dat > out.txt``` (out.txt can be anything you want)


