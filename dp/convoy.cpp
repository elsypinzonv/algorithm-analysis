// https://omegaup.com/arena/problem/Convoy/#problems
#include <iostream>
#include <vector>
using namespace std;

const int MAX=1005;
int memo[MAX][MAX];
bool visit[MAX][MAX];

int b, l, n;

int maxi(int i, int sum, vector< pair<int, int> > &v){
	int s = 0;
	int maximo = -1111111;
	for(int j = i + 1; j< v.size(); j++){
		s+= v[j].first;
		maximo = max(maximo, v[j].second);
		if(s == sum) return maximo;
	}
	return maximo;
}

int dp(int i, int sum, vector< pair<int, int> > &v){
	 if(i == 0) return 0;
	 cout << i << ' ' << sum << '\n';
	 if(visit[i][sum] == true ) return memo[i][sum]; 
	 visit[i][sum] = true; 
	 int ans = dp(i-1, v[i].first + maxi(i, sum,v),v);
	 if(v[i].first + sum <= b){
	 	ans = min(ans, dp(i-1, sum + v[i].first,v));
	 }
	 return memo[i][sum] = ans;
}

void solve(){

	while(cin >> b >> l >> n and (b != 0 && (l != 0 && n!=0))){
		vector< pair<int, int> > v(n);
		int w, s, t;
		for(int i = 0; i < n; i++){
			cin >> w >> s;
			t = l/s;
			v[i] = {w,t};
		}
		cout << '\n' <<dp(n-1, 0, v) << '\n';
	}

}

int main(){
	ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
	solve();
	return 0;
}