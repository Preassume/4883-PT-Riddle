#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> primes;

/*
 * write a binary tree for every input number. it will have prime
 * numbers that can compose it in every possible combination
 * branching down. the depth of the end node with least depth is the
 * answer
*/

struct thing{
	thing* head;
	vector<thing*> children;
	int value, branchValue, depth;
	
	// Constructor for the head of the tree
	thing(int h){
		value = h;
		branchValue = 0;
		depth = 0;
		
		for(auto x : primes){
			if(x <= value){
				children.push_back(new thing(this, x, x, 1));
			}
		}
	}
	
	// Constructor for children of the head
	thing(thing* h, int v, int t, int d){
		head = h;
		branchValue = t;
		value = v;
		depth = d;
		
		if(branchValue < head->value){
			int nextChild = 0;
			for(auto x : primes){
				if(x > nextChild && (x + branchValue) <= head->value){
					nextChild = x;
				}
			}
			children.push_back(new thing(head, nextChild, nextChild + branchValue, depth + 1));
		}
	}
	
	~thing(){
		if(!children.empty())
			for(auto x : children)
				delete x;
	}
};

void printThing(thing* t){
	if(t->children.empty()) return;
	
	for(auto x : t->children){
		cout << x->value << ' ';
		printThing(x);
	}
}

void printThingDepth(thing* t){
	if(t->children.empty()) return;
	
	for(auto x : t->children){
		cout << x->depth << ' ';
		printThingDepth(x);
	}
}

int shortestDepth = INT_MAX;
void findAnswer(thing* t){
	if(t->children.empty()){
		if(t->depth < shortestDepth)
			shortestDepth = t->depth;
		return;
	}
	for(auto x : t->children){
		findAnswer(x);
	}
}

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

void getPrimes(int n){
	primes.clear();
	primes.push_back(1); // We also need a 1, so we add it even though it's not prime
	
	for(int i = 2; (int)primes.size() < n; i++){
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
		getPrimes(n);
		thing* head = new thing(q);
		shortestDepth = INT_MAX;
		findAnswer(head);
		cout << shortestDepth << '\n';
		delete head;
	}
	
	/*
	cin >> n >> q;
	getPrimesN(n);
	for(auto x : primes) cout << x << '\n';
	cout << "\n\n";
	thing* head = new thing(q);
	printThing(head);
	cout << '\n';
	printThingDepth(head);
	shortestDepth = INT_MAX;
	findAnswer(head);
	cout << '\n' << shortestDepth << '\n';*/
}
