#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

void process(vector< pair<long double, long double> > v, long double m){
	vector< pair<long double, long double> > result;
	pair<long double, long double> best;
	
	long double x = 0, sum, i;
	best = {-1,+1};
	x = sum = i = 0;

	while( i < v.size()){
		pair<long double, long double> s = v[i];
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
		cout << -1 << '\n';
	}else{
		cout << sum << '\n';
	} 
}

void solve(){
	long double n, w, l;
	while(cin >> n >> l >> w){
		long double d, r;
		vector < pair<long double, long double> > p;
		long double b;
		for(int i = 0; i < n; i++){
			cin >> d >> r;
			if((w/2) < r){
				b = sqrt((r*r) - ((w/2)*(w/2)));
				p.push_back({d-b, (d+b)*-1});	
			}		
		}
		sort(p.begin(), p.end());
		process(p, l);
	}
}

int main(){
	ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
	solve();
	return 0;
}