## 161 - Traffic Lights
### Austin Riddle
### Description:

One way of achieving a smooth and economical drive to work is to ‘catch’ every traffic light, that is
have every signal change to green as you approach it. One day you notice as you come over the brow of
a hill that every traffic light you can see has just changed to green and that therefore your chances of
catching every signal is slight. As you wait at a red light you begin to wonder how long it will be before
all the lights again show green, not necessarily all turn green, merely all show green simultaneously,
even if it is only for a second.
Write a program that will determine whether this event occurs within a reasonable time. Time is
measured from the instant when they all turned green simultaneously, although the initial portion while
they are all still green is excluded from the reckoning.

I opted for a highly organized code structure for this problem, for better or for worse.  Each stage of the problem is encapsulated into its own function.  In addition, each traffic light is represented by a ```light``` structure which handles some simple logic for incrementing the lights and checking if it's green or not.  Perhaps it isn't the fastest way, but it's what jumped out to me.

I think the code could probably be simplified further, but for now, it works.

### Files


|   #   | File                       | Description                                                |
| :---: | -------------------------- | ---------------------------------------------------------- |
|   1   |[traffic.cpp](./traffic.cpp)| Solution Source Code.                                      |
|   2   | [data.dat](./data.dat)     | Test input file from uDebug.                               |
|   3   | [161.pdf](./161.pdf)       | Original problem description document.                     |

### Instructions

- This project was compiled with GNU GCC 11.1.0.  It should work with any C++11 or newer compiler.
- Simply compile traffic.cpp and run the executable. ```g++ traffic.cpp -o traffic```
- To supply the input and output to a file, run it like this: ```./traffic < data.dat > out.txt```

### Sources

- C++ Reference
    - https://www.cplusplus.com/reference/




