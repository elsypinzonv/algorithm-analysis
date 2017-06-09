// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=944
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

const int MAX=1005;
int memo[MAX][MAX];
int visit[MAX][MAX];
const int INF = 50*1000;
int color;


int dp(int i, int j, vector<int> &v){
	int ans = INF;
	if(visit[i][j] == color) return memo[i][j];
	visit[i][j] = color;
	for(int k = 0; k < v.size(); k++){
		if( i < v[k]  && v[k] < j){
			ans = min(dp(i, v[k], v ) + dp(v[k], j, v) + (j-i), ans); 
		}
	}
	if(ans == INF) return 0;
	return memo[i][j] = ans; 
}

void solve(){
	int l, n;
	while(cin >> l and l != 0){
		cin >> n;
		vector<int> v(n);
		for(int i = 0; i < n; i++){
			cin >> v[i];
		}
		color++;
		cout << "The minimum cutting is " << dp(0,l, v) << "." << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
	solve();
	return 0;
}