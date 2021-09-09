# Assignment 6

### Austin Riddle

#### For CMPS 4883 Programming Techniques.

#### 9/9/2021

This is a problem __10038__ from https://onlinejudge.org/ called __Jolly Jumpers__.

In order to solve this problem, I chose to use a ```set``` type that contains long integers.  I did this because sets can only contian unique elements, meaning no duplicates could be stored in it.  That made it easier to detect if there were duplicates, as I would only have to check the size of the set to know if we got duplicate values from the absolute value of the differences of the successive elements.  That's important, because in order for a set to be a Jolly Jumper, it cannot have duplicate elements, as then it would not be able to have all elements from 1 to _n - 1_.  The only other things I needed to check for are that it must not contain elements less than 1, nor greater than _n - 1_.  And, if our set only contains one element, then that element must be 1.  In addition, if the input only provides one value, then we don't even make a set at all, as those inputs are always considered Jolly Jumpers as specified by the problem.
