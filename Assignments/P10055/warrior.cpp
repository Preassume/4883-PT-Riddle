/**
 * Austin Riddle
 * CMPS 4883 PT
 * 08/31/2021
 */

#include <iostream>

using namespace std;

int main(){
	long int a = 0;
	long int b = 0;
	
	// Keep looping as long as we continue to get input
	while(cin >> a >> b){
		
		// Always subtract the smaller number from the larger number
		if(a > b)
			cout << a - b << '\n';
		else
			cout << b - a << '\n';
	}
}
