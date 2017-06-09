//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1415
#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> &v,int &n){
	int start, end, mid,answer;
	start=0;
	answer=-1;
	end=v.size()-1;
	while(start<=end){
		mid=(start+end)/2;
		if(v[mid]==n) answer=mid;
		if(v[mid]<n) start=mid+1;
		if(v[mid]>=n) end=mid-1;
	}
	return answer;
}

void merge(vector<int> &v,vector<int> &left,vector<int> &rigth){
	int iRigth=0;
	int iLeft=0;
	for(int i=0; i<(left.size()+rigth.size()); i++){
		if(iRigth>=rigth.size()){
			v[i]=left[iLeft];
			iLeft++;
			continue;
		}
		if(iLeft>=left.size()){
			v[i]=rigth[iRigth];
			iRigth++;
			continue;
		}
		if(left[iLeft]>rigth[iRigth]){
			v[i]=rigth[iRigth];
			iRigth++;
		}else{
			v[i]=left[iLeft];
			iLeft++;
			
		}
	}
}

void mergeSort(vector<int> &v){
	if(v.size()==1) return; 
	vector<int> left(v.begin(), v.begin() + v.size()/2);
	vector<int> rigth(v.begin() + v.size()/2 , v.end());
	mergeSort(left);
	mergeSort(rigth);
	merge(v, left, rigth);
}

void solve(){
	int n,q,_case;
	_case=1;
	while(cin>>n>>q and (n or q)){
		vector<int> v(n);
		for(int i=0; i<n; i++){
			cin>>v[i];
		}
		mergeSort(v);
		int test;
		cout<<"CASE# "<<_case<<":\n";
		for(int i=0; i<q; i++){
			cin>>test;
			int result=binarySearch(v,test);
			if(result==-1){
				cout<<test<<" not found"<<'\n';
			}else cout<<test<<" found at "<<result+1<<'\n';
		}
		_case++;
	}	
}

int main(){
	ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
	solve();
	return 0;
}