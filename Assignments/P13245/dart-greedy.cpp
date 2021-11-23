// Austin Riddle
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> primes;

// Get the first 100 prime numbers, as that is the most we will need.
void getPrimes(){
	primes.push_back(1); // We also need a 1, so we add it even though it's not prime
	
	for(int i = 2; i <= 541; i++){ // 541 is the 100th prime
		bool isPrime = true;
		
		for(int j = 2; j < i; j++){
			if(i % j == 0)
				isPrime = false;
		}
		
		if(isPrime) primes.push_back(i);
	}
}

// Get the minimum number of darts required to get the desired points
// using only the first n prime numbers
int numDarts(int n, int q){
	int evenCounter, counter = 0, sum = 0;
	for(auto i = primes.begin() + (n-1); i >= primes.begin(); i--){
		if(q % *i == 0){
			evenCounter = q / *i;
			break;
		}
	}
	for(auto i = primes.begin() + (n-1); i >= primes.begin(); i--){
		//cout << *i << ' ';
		while(sum + *i <= q){
			//cout << '\n' << *i << '\n';
			sum += *i;
			counter++;
		}
			
		if(sum == q){
			return min(counter, evenCounter);
		}
	}
	return -1;
}

int main(){
	getPrimes();
	//for(auto x : primes) cout << x << '\n';
	int cases, n, q;
	cin >> cases;
	while(cases--){
		cin >> n >> q;
		getPrimes();
		cout << numDarts(n, q) << '\n';
	}
}
