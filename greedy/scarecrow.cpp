#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

void solve(){
	int t;
	cin >> t;
	int n;
	string s;
	
	for(int j = 1; j <= t; j++){
		cin >> n >> s;

		int i = 0;
		int sum = 0;
		while(i < n){
			if(s[i] == '.'){
				i += 3;
				sum++;
			}else i++;
		}
		cout << "Case "<<j<<": "<< sum <<'\n';
	}

}

int main(){
	ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
	solve();
	return 0;
}