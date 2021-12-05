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

I tried a few approaches to this problem. The two most notable ones are in this repository. The first, dart-greedy.cpp, basically just iterates through all available prime numbers, starting with the largest, and sums up the largest primes it can without going over the score. This works for many cases, but there are still a lot of cases where this is not optimal.

My second approach, found in dart-tree.cpp, was similar. Where it differs, though, is that I basically forced the algorithm to have different primes to start with. Basically, we test the same algorithm once for every available prime number, starting the algorithm with that prime number. This improved the number of successful cases, purely just by testing more possible combinations, but there were still exceptions, since the algorithm didn't test _every_ combination.

In addition to a few oddball approaches I tried, I also attempted to brute force the problem, testing every possible combination. The resulting program ran for a little over 2 days before I realized that I had made an error in the code. It hadn't finished executing, though it was probably only a few hours away. The results it _did_ complete were mostly wrong though, so I did not pursue this approach any further.

### Files


|   #   | File                                | Description                              |
| :---: | ----------------------------------- | ---------------------------------------- |
|   1   |[dart-greedy.cpp](./dart-greedy.cpp) | First approach source code.              |
|   2   |[dart-tree.cpp](./dart-tree.cpp) | Second approach source code.                 |
|   3   |[data.dat](./data.dat)               | Test input file from uDebug.             |
|   4   |[13245.pdf](./13245.pdf)       | Original problem description document.   |

### Instructions

- This project was compiled with GNU GCC 11.1.0.  It should work with any C++11 or newer compiler.
- Simply compile d.cpp and run the executable. ```g++ dart-tree.cpp -o dart-tree```
- To supply the input file, run it like this: ```./dart-tree < data.dat```
- To output to a file, run it like this: ```./dart-tree < data.dat > out.txt``` (out.txt can be anything you want)
- The same can be also done with ```dart-greedy``` instead.


### Sources
- C++ Reference
    - https://www.cplusplus.com/reference/
- Geeks for Geeks
    - https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
