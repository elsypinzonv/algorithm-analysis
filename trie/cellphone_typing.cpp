#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>
#include <math.h>

using namespace std;

struct Node {
	vector<Node*> v;
	bool isFinal;
	int nodes;

	Node():
		isFinal(false), nodes(0), v(26){}

};

struct  Trie{

	Node* root;

	Trie():
		root(new Node()){}

	void insert(string s){
		Node *current = root;
		for(int i = 0; i < s.size(); i++){
			if(current -> v[s[i]-'a'] == NULL){
				current ->v[s[i]-'a'] = new Node();
				current -> nodes++;
			}
			current = current -> v[s[i]-'a'];
		}
		current -> isFinal = true;
	} 
	
	int query(string s){
		int sum = 0;
		Node * current = root;
		for(int i = 0; i < s.size(); i++){
			current = current -> v[s[i]-'a'];
			if(current -> nodes > 1 || current -> isFinal == true){
				sum++;
			}
		}
		return sum;
	}	

};

void solve(){

	
	int n;
	string s;
	
	while(cin >> n){
		
		Trie *trie = new Trie();
		vector<string> v;

		for(int i = 0; i < n; i++){
			cin >> s;
			trie -> insert(s);
			v.push_back(s);
		}

		double sum = 0;
		for(int i = 0; i < v.size(); i++){
			sum += trie -> query(v[i]);
		}
		double f = (double) v.size();
		cout << fixed << setprecision(2) << (sum/f)<<'\n';
	}

}

int main(){
	ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
	solve();
	return 0;
}