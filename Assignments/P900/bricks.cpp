 /**
 * Austin Riddle
 * CMPS 4883
 * 9/30/2021
 */

#include <iostream>

using namespace std;

int main(){
	uint64_t fibonacci[2]; // We only need the last two digits of the sequence
	
	int input;
	while(cin >> input){
		if(input == 0) return 0;
		
		// Initialize the fibonacci sequence
		fibonacci[0] = 0;
		fibonacci[1] = 1;
		
		while(input--){
			auto tmp = fibonacci[1];
			fibonacci[1] += fibonacci[0]; // Get the next fibonacci number
			fibonacci[0] = tmp;
		}
		cout << fibonacci[1] << '\n'; // Print the largest fibonacci number we made
	}
}
