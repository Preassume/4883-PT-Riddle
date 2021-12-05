## 10226 - Hardwood Species
### Austin Riddle
### Description:

Hardwoods are the botanical group of trees that have broad leaves, produce a fruit or nut, and generally go dormant in the winter. America’s temperate climates produce forests with hundreds of hardwood species —trees that share certain biological characteristics. Although oak, maple and cherry all are types of hardwood trees, for example, they are different species. Together, all the hardwood species represent 40 percent of the trees in the United States. On the other hand, softwoods, or conifers, from the Latin word meaning “cone-bearing”, have needles. Widely available US softwoods include cedar, fir, hemlock, pine, redwood, spruce and cypress. In a home, the softwoods are used primarily as structural lumber such as 2×4s and 2×6s, with some limited decorative applications. Using satellite imaging technology, the Department of Natural Resources has compiled an inventory of every tree standing on a particular day. You are to compute the total fraction of the tree population represented by each species.

My hardwood species code found in tree.cpp is working great. I used a std::map container to keep track of the tree species. The key is the species name and the value is the number of times that species has occurred. Something to note is that I used a long double to keep track of the number of species. This allowed for a decimal approximation of the percentages of each species to be generated.

### Files


|   #   | File                                | Description                              |
| :---: | ----------------------------------- | ---------------------------------------- |
|   1   |[tree.cpp](./tree.cpp) | Solution source code.                    |
|   2   |[data.dat](./data.dat)               | Test input file from uDebug.             |
|   3   |[10226.pdf](./10226.pdf)       | Original problem description document.   |

### Instructions

- This project was compiled with GNU GCC 11.1.0.  It should work with any C++11 or newer compiler.
- Simply compile tree.cpp and run the executable. ```g++ tree.cpp -o tree```
- To supply the input file, run it like this: ```./tree < data.dat```
- To output to a file, run it like this: ```./tree < data.dat > out.txt``` (out.txt can be anything you want)

### Sources
- C++ Reference
    - https://www.cplusplus.com/reference/

