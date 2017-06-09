//http://codeforces.com/problemset/problem/192/A
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

const int MAX_FUNKY=45000;

bool binarySearch(vector<int> &v, int &n){
	int start, end, mid,answer;
	start=0;
	end=v.size()-1;
	while(start<=end){
		mid=(start+end)/2;
		if(v[mid]==n) return true;
		if(v[mid]<n) start=mid+1;
		if(v[mid]>n) end=mid-1;
	}
	return false;
}

void fillFunkyNumbers(vector<int> &v){
	for(int i=1; i<=MAX_FUNKY; i++){
		v[i-1]=(i*(i+1))/2;
	}
}

void solve(){
	int n;
	cin>>n;
	vector<int> v(MAX_FUNKY);
	fillFunkyNumbers(v);
	int dif;
	bool flag=0;
	for(int i=0; i<MAX_FUNKY; i++){
		dif=n-v[i];
		if(binarySearch(v,dif)){
			cout<<"YES"<<'\n';
			return;
		}
	}
	cout<<"NO"<<'\n';
}

int main(){
	ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
	solve();
	return 0;
}