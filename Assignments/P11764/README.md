## 11764 - Jumping Mario
### Austin Riddle
### Description:

Mario is in the final castle. He now needs to jump
over few walls and then enter the Koopa’s Cham-
ber where he has to defeat the monster in order to
save the princess. For this problem, we are only con-
cerned with the “jumping over the wall” part. You
will be given the heights of N walls from left to right.
Mario is currently standing on the first wall. He has
to jump to the adjacent walls one after another until
he reaches the last one. That means, he will make
(N − 1) jumps. A high jump is one where Mario has
to jump to a taller wall, and similarly, a low jump is
one where Mario has to jump to a shorter wall. Can you find out the total number of high jumps and
low jumps Mario has to make?

### Files


|   #   | File                                | Description                              |
| :---: | ----------------------------------- | ---------------------------------------- |
|   1   |[mario.cpp](./mario.cpp) | Solution source code.                    |
|   2   |[data.dat](./data.dat)               | Test input file from uDebug.             |
|   3   |[11764.pdf](./11764.pdf)       | Original problem description document.   |

### Instructions

- This project was compiled with GNU GCC 11.1.0.  It should work with any C++11 or newer compiler.
- Simply compile mario.cpp and run the executable. ```g++ mario.cpp -o mario```
- To supply the input file, run it like this: ```./mario < data.dat```
- To output to a file, run it like this: ```./mario < data.dat > out.txt``` (out.txt can be anything you want)

### Sources
- C++ Reference
    - https://www.cplusplus.com/reference/

