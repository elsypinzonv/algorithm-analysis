//http://www.spoj.com/problems/RMQSQ/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void createSegmentTree(vector<int> &ST,vector<int> &nums,int node, int start, int end){
	if(start==end){
		ST[node]=nums[start];
	}else{
		int mid = (start+end)/2;
		createSegmentTree(ST,nums,node*2,start,mid);
		createSegmentTree(ST,nums,node*2+1, mid+1,end);
		ST[node]=min(ST[node*2],ST[node*2+1]);
	}
}

int query(vector<int> &ST,int node, int start, int end, int i, int j){
	if(j<start || end<i) return INT_MAX;
	if(i<=start && end<=j) return ST[node];
	int mid = (start + end)/2;
	int left = query(ST,node*2,start,mid,i,j);
	int right = query(ST,node*2+1,mid+1,end,i,j);
	return min(left,right);
}

void solve(){
	int n;
	cin>>n;
	vector<int> ST(3*n+1);
	vector<int> nums(n+1);
	for(int i=0; i<n; i++){
		cin>>nums[i];
	}
	const int NODE=1;
	const int START=0;
	const int END=n-1;

	createSegmentTree(ST,nums,NODE,START,END);
	
	int q;
	cin>>q;
	int a,b;
	for(int i=0; i<q; i++){
		cin>>a>>b;
		cout<<query(ST,NODE,START,END,a,b)<<'\n';
	}
}

int main(){
	ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
	solve();
	return 0;
}