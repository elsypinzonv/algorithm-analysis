// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1437
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

const int MAX=25;
const int MAX2 = 1<<12;
int memo[MAX2][MAX];
int visit[MAX2][MAX];
int graph[MAX][MAX];
int INF = 4000;
int color;

int dp(int mask, int current, int n){
	if(mask == ((1 << n)-1)){
		return graph[current][0];	
	} 
	int ans = INF;
	if(visit[mask][current] == color) return memo[mask][current];
	visit[mask][current] = color;

	for(int i = 0; i < n; i++){
		if(i == current) continue;
		if((mask&(1<<i)) == 0){
			ans = min(ans, dp( (mask|(1<<i)),i ,n) + graph[current][i]); 
		}
	}
	
	return memo[mask][current] = ans;
}

void solve(){
	int t;
	cin >> t;	
	for(int i = 0; i < t; i++){
		int m, n, x, y, b;
		cin >> m >> n >> x >> y >> b;
		vector< pair <int, int> > v(b + 1);
		v[0] = {x, y};
		for(int j = 1; j <= b; j++){
			cin >> x >> y;
			v[j] = {x, y}; 
		}
		for(int j = 0; j < v.size(); j++){
			for(int k = 0; k < v.size(); k++){
				graph[j][k] = abs(v[j].first - v[k].first) + abs(v[j].second - v[k].second);
			}
		}
		color++;
		cout <<"The shortest path has length "<< dp(1, 0, b+1 ) << '\n';
	}	
}

int main(){
	ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
	solve();
	return 0;
}	