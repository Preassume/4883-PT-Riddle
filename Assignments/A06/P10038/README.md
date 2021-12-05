## 10038 - Jolly Jumpers
### Austin Riddle
### Description:

A sequence of n > 0 integers is called a jolly jumper if the absolute values of the difference between successive elements take on all the values 1 through n − 1. For instance,
1 4 2 3
is a jolly jumper, because the absolutes differences are 3, 2, and 1 respectively. The definition implies that any sequence of a single integer is a jolly jumper. You are to write a program to determine whether or not each of a number of sequences is a jolly jumper.

In order to solve this problem, I chose to use a ```set``` type that contains long integers.  I did this because sets can only contian unique elements, meaning no duplicates could be stored in it.  That made it easier to detect if there were duplicates, as I would only have to check the size of the set to know if we got duplicate values from the absolute value of the differences of the successive elements.  That's important, because in order for a set to be a Jolly Jumper, it cannot have duplicate elements, as then it would not be able to have all elements from 1 to _n - 1_.  The only other things I needed to check for are that it must not contain elements less than 1, nor greater than _n - 1_.  And, if our set only contains one element, then that element must be 1.  In addition, if the input only provides one value, then we don't even make a set at all, as those inputs are always considered Jolly Jumpers as specified by the problem.

### Files


|   #   | File                                | Description                              |
| :---: | ----------------------------------- | ---------------------------------------- |
|   1   |[jolly.cpp](./jolly.cpp) | Solution Source Code.                    |
|   2   |[data.dat](./data.dat)               | Test input file from uDebug.             |
|   3   |[10038.pdf](./10038.pdf)       | Original problem description document.   |

### Instructions

- This project was compiled with GNU GCC 11.1.0.  It should work with any C++11 or newer compiler.
- Simply compile jolly.cpp and run the executable. ```g++ jolly.cpp -o jolly```
- To supply the input file, run it like this: ```./jolly < data.dat```
- To output to a file, run it like this: ```./jolly < data.dat > out.txt``` (out.txt can be anything you want)

### Sources
- C++ Reference
    - https://www.cplusplus.com/reference/

