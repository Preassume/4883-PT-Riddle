/**
 * Austin Riddle
 * CMPS 4883
 * 9/9/2021
 */

#include <iostream>
#include <cmath>
#include <set>

using namespace std;

// We get our input sequence and take the absolute value of the 
// difference of the successive elements.
// Then, we store that into a set to avoid duplicates.
// Returns the set.
set<long int> getSequence(int n){
	set<long int> sequence;
	long int tmp1, tmp2; // Two integers so we can take the difference
	cin >> tmp1;
	for(int i = 0; i < n - 1; i++){
		cin >> tmp2;
		sequence.insert(abs(tmp1 - tmp2));
		tmp1 = tmp2;
	}
	return sequence;
}

// Checks if a sequence is a jolly jumper.
// Returns true if it is, false if it isn't.
bool isJolly(set<long int> sequence, int n){
	
	// In order to be a jolly jumper, we can't have duplicate elements.
	// Since sequence is a set, if its size is not n - 1, then it means we
	// got duplicates while gathering the input. So, return false.
	if(sequence.size() < n - 1) return false;
	
	// If the sequence only contains one value, then that value must be 1.
	// Otherwise, it's not a jolly jumper.
	if(sequence.size() == 1){
		if(sequence.find(1) == sequence.end()) return false;
	}
	
	// If x starts at 0, then we're not a jolly jumper.
	// If x is ever larger than n - 1, then we're not a jolly jumper.
	for(auto x : sequence){
		if(x < 1) return false;
		if(x >= n) return false;
	}
	
	// After passing all previous tests, we must be a jolly jumper.
	return true;
}

int main(){
	int n;
	while(cin >> n){
		if(n == 1){ // All single-value inputs are jolly jumpers.
			cin >> n; // cin again to move us forward in the input.
			cout << "Jolly\n";
		}
		else{
			if(isJolly(getSequence(n), n))
				cout << "Jolly\n";
			else
				cout << "Not jolly\n";
		}
	}
}
