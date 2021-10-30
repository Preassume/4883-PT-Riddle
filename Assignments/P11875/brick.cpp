 /**
 * Austin Riddle
 * CMPS 4883
 * 11/02/2021
 */
#include <iostream>
#include <vector>

using namespace std;

int main(){
	int cases, teamSize, captain, counter = 0;
	cin >> cases;
	
	while(cases--){
		counter++;
		cin >> teamSize;
		
		if(teamSize == 1)
			cin >> captain;
		else{
			for(int i = 0; i < teamSize; i++){
				int tmp;
				cin >> tmp;
				
				// Since input is already ordered, the captain is always in the middle
				if(i == teamSize / 2)
					captain = tmp;
			}
		}
		cout << "Case " << counter << ": " << captain << '\n';
	}
}
