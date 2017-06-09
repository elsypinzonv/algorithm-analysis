#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#include <algorithm>

using namespace std;

struct Node {
	map<char, Node*> v;
	bool isFinal;

	Node():
		isFinal(false){}

};

struct  Trie{

	Node* root;

	Trie():
		root(new Node()){}

	void insert(string &s){
		Node *current = root;
		for(int i = 0; i < s.size(); i++){
			if(current -> v[s[i]] == NULL){
				current ->v[s[i]] = new Node();
			}
			current = current -> v[s[i]];
		}
		current -> isFinal = true;
	} 
	
	void query(string &s, int index, bitset<500001> &dp){
		Node * current = root;
		for(int i = index; i < s.size(); i++){
			current = current -> v[s[i]];
			if(current == NULL) return;
			if(current != NULL){
				if(current -> isFinal == true) dp[i+1] = 1;	
			}
			
		}
	}	

};

void solve(){

	int n;
	cin >> n;
	string p;
	Trie *trie = new Trie();
	for(int i = 0; i < n; i++){
		cin >> p;
		trie -> insert(p);
	}

	string q;
	cin >> q;
	bitset<500001> dp;
	dp[0] = 1;
	for(int i = 0; i < q.size(); i++){
		if(dp[i] == 1){
			trie -> query(q, i, dp);
		}
	}

	for(int i = q.size(); i >= 0; i--){
		if(dp[i]){
			cout << i << '\n';
			break;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
	solve();
	return 0;
}