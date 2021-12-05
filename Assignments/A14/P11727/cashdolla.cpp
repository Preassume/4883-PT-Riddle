 /**
 * Austin Riddle
 * CMPS 4883
 * 11/02/2021
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int cases, counter = 0;
	vector<int> salaries;
	
	cin >> cases;
	while(cases--){
		counter++;
		salaries.clear();
		
		for(int i = 0; i < 3; i++){
			int tmp;
			cin >> tmp;
			salaries.push_back(tmp);
		}
		sort(salaries.begin(), salaries.end());
		// After sorting, the answer will always be the 2nd element in the vector
		cout << "Case " << counter << ": " << salaries[1] << '\n';
	}
}
