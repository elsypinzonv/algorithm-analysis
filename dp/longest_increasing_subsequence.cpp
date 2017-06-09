// http://www.spoj.com/problems/ELIS/
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

const int MAX=15;
int memo[MAX][MAX];
bool visit[MAX][MAX];


int dp(int i, int last, vector<int> &v){
	if(i == v.size()) return 0;
	if(visit[i][last] == true) return memo[i][last];
	visit[i][last] = true;
	int ans = dp(i + 1 , last, v);
	if(v[i] > v[last] ){
		ans = max(ans, dp(i+1, i, v) + 1);
	}
	return memo[i][last] = ans;
}

void solve(){
	int n;
	cin >> n;
	vector<int> v(n + 1);
	v[0] = -1;
	for(int i = 1; i <= n; i++){
		cin >> v[i];
	}
	cout << dp(1, 0, v) << '\n';
}

int main(){
	ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
	solve();
	return 0;
}