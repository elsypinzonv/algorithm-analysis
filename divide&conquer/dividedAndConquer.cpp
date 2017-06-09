#include<iostream>
#include<vector>
using namespace std;
 
 const long long int inf= -1e15;

long long int getMaxSum(vector<int> &v){
	long long int inv = inf;
	if(v.size()==1) return v[0];
	vector<int> izq(v.begin(), v.begin() + v.size()/2);
	vector<int> der(v.begin() + v.size()/2, v.end());
	long long int sum=0;
	long long int max1,max2;
	max1=max2=inf;
	for(int i=v.size()/2 - 1; i>=0; i--){
		sum+=v[i];
		max1=max(max1,sum);
	}
	sum=0;
	for(int i=v.size()/2; i<v.size(); i++){
		sum+=v[i];
		max2=max(max2,sum);
	}
	sum=max1+max2;
	inv = max(sum,max(getMaxSum(izq),getMaxSum(der)));
	return inv;
}
 
void solve(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0; i<n; i++){
		cin>>v[i];
	}
	cout<<getMaxSum(v)<<'\n';
}
 
int main(){
	ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
	solve();
	return 0;
} 