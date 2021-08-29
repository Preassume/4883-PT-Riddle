# Assignment 4

### Austin Riddle

#### For CMPS 4883 Programming Techniques.

#### 08/31/2021

This is a simple problem from https://onlinejudge.org/

Specifically, it is problem number __10055__ called __Hashmat the brave warrior__

My code for this is similar to the starter code provided, however I used `long int` for my variables instead of regular `int`.  This made the difference between passing and failing on Online Judge.

Additionally, my loop contained a simple if/else statement to make sure that the smaller number is always subtracted from the larger number.
```cpp
if(a > b)
	cout << a - b << '\n';
else
	cout << b - a << '\n';
```

For testing, I used the contents of `input.dat` to make sure the program worked.  This contains input data from the Online Judge debugging website so that I could make sure I got the correct output.
