/**
 * Austin Riddle
 * 4883
 * 11/23/2021
 */
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Our node structure. Used for creating the binary tree.
struct node{
	node* parent;
	node* left;
	node* right;
	int value, sum;
	bool leaf;
	
	node(){
		parent = left = right = nullptr;
		value = sum = 0;
		leaf = true;
	}
	
	~node(){
		delete left;
		delete right;
	}
};

node head; // Head always exists

// A simple function that counts how many opening and closing parentheses
// characters are in a string. If they are equal, then our s-expression must be complete
bool complete(string s){
	if((int)s.size() == 0) return false;
	int open = 0, close = 0;
	for(auto c : s){
		if(c == '(') open++;
		else if(c == ')') close++;
	}
	if(open == 0 && close == 0) return false;
	return open == close;
}

// Takes our s-expression as an input and creates a binary tree based on
// its parameters. The tree nodes keep track of their current sum.
void createTree(string sExp){
	string tmp = "";
	int layer = 0;
	node* current = &head;
	bool isNegative = false;
	
	for(int i = 0; i < (int)sExp.size(); i++){
		if(sExp[i] >= '0' && sExp[i] <= '9'){ // If the character is numerical, keep track of it
			tmp += sExp[i];
		}
		else if(sExp[i] == '-'){ // If we're negative, keep track of that
			isNegative = true;
		}
		else{ // We encountered a non-numerical character. Now we get the integer value from our number string
			if(tmp != ""){
				int num = 0, size = (int)tmp.size();
				
				// Iterate through our number string (tmp) and place each character into our integer (num)
				for(int j = 0; j < size; j++){
					int c = tmp[(size-1)-j] - 48;
					num += c * pow(10, j);
				}
				if(isNegative){
					num *= -1;
					isNegative = false; // Reset isNegative for next time
				}
				tmp = ""; // Reset our number string
				
				if(layer == 1){ // Don't need to do much if we're on the first layer (the head)
					current->value = num;
					current->sum += num;
				}
				// Otherwise, we need to create a new node and give it the appropriate data
				else{
					node* tmp = new node;
					tmp->parent = current;
					tmp->sum += current->sum;
					tmp->value = num;
					tmp->sum += num;
					
					if(current->left == nullptr){
						current->leaf = false;
						current->left = tmp;
						current = tmp;
					}
					else if(current->right == nullptr){
						current->leaf = false;
						current->right = tmp;
						current = tmp;
					}
				}
			}
		}
		// These keep track of how deep we are in the tree via the parentheses
		if(sExp[i] == '('){
			layer++;
		}
		else if(sExp[i] == ')'){
			layer--;
			if(i > 0){ // If there was previously a node in the s-expression, go back to that node
				if(sExp[i-1] != '('){
					current = current->parent;
				}
			}
		}
	}
}

// Gets the sums of all leaf nodes (which have no children.)
// Places them into leafSums vector.
vector<int> leafSums;
void getSums(node* ptr){
	if(ptr->leaf) leafSums.push_back(ptr->sum);
	else{
		if(ptr->left) getSums(ptr->left);
		if(ptr->right) getSums(ptr->right);
	}
}

// Erases the entire binary tree and re-initializes the head node.
void clearTree(){
	delete head.left;
	delete head.right;
	head.parent = head.left = head.right = nullptr;
	head.sum = head.value = 0;
}

int main(){
	int num;
	while(cin >> num){
		
		// Gather our s-expression
		string in;
		while(!complete(in)){
			string tmp;
			cin >> tmp;
			in += tmp;
		}
		
		// Check of our s-expression contains any nodes
		bool isGood = false;
		for(auto c : in){
			if(c >= '0' && c <= '9') isGood = true;
		}
		
		if(isGood){
			// Make the tree and gather the root-to-leaf path sums
			createTree(in);
			leafSums.clear();
			getSums(&head);
			
			// Clear the tree for next time
			clearTree();
			
			// Check if our input number exists in our root-to-leaf path sums
			bool exists = false;
			for(auto x : leafSums){
				if(x == num){
					exists = true;
					break;
				}
			}
			if(exists) cout << "yes\n";
			else cout << "no\n";
		}
		else cout << "no\n";
	}
}
