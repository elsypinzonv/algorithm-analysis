#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void process(vector< pair<int, int> > v, int m){
	vector< pair<int, int> > result;
	pair<int, int> best;
	
	int x, sum , i;
	best = {-1,+1};
	i = x = sum = 0;

	while( i < v.size()){
		pair<int, int> s = v[i];
		if(x >= m) break;
		if(x >= s.first && x <= s.second*-1){
			if(s.second*-1 > best.second*-1) best = s;
			i++;
			continue;
		}
		if(x > s.second*-1){
			i++;
			continue;
		} 	
		if(x < s.first){
			if( x >= best.first  && x <= best.second*-1){
					result.push_back(best);
					x = best.second*-1 ; 
					best = {-1,+1};
					sum++;
			}else {
				sum = -1;
				break;
			}
		}
	}
	if( x >= best.first  && x <= best.second*-1){
		result.push_back(best);
		x = best.second*-1;
		sum++;
	}
	if(sum == -1 || x < m ){
		cout << 0 << '\n';
	}else{
		cout << sum << '\n';
		for(int i = 0; i < result.size(); i++){
			cout << result[i].first << ' ' << result[i].second*-1 << '\n';
		}	 
	} 
}

void solve(){
	int t;
	cin >> t;
	int m;
	for(int i = 0; i < t; i++){
		cin >> m;
		int a, b;
		vector < pair<int, int> > p;
		while(cin >> a >> b and (a!=0 || b!=0)){
			p.push_back({a,-1*b});
		}
		sort(p.begin(), p.end());
		process(p, m);
		if(i != t-1)cout <<'\n';

	}
}

int main(){
	ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
	solve();
	return 0;
}