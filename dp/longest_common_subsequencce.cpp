// https://omegaup.com/arena/problem/Longest-Common-Subsequence/#problems
#include <iostream>
#include <math.h>
using namespace std;

const int MAX=1005;
int memo[MAX][MAX];
bool visit[MAX][MAX];
string a, b;

int dp(int i, int j){
	if(i == -1 || j == -1) return 0;
	if(visit[i][j] == true) return memo[i][j];
	visit[i][j] = true;
	int ans = max(dp(i-1,j),dp(i, j-1));
	if(a[i] == b[j]){
		ans = max(ans, dp(i-1,j-1)+1);
	}
	return memo[i][j] = ans;
}

void solve(){
	cin >> a >> b;
	cout << dp(a.size()-1, b.size()-1)<< '\n';
}

int main(){
	ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
	solve();
	return 0;
}