#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &v,vector<int> &izq,vector<int> &der,long long int &inv){
	int iDer=0;
	int iIzq=0;
	for(int i=0; i<(izq.size()+der.size()); i++){
		if(iDer>=der.size()){
			v[i]=izq[iIzq];
			iIzq++;
			continue;
		}
		if(iIzq>=izq.size()){
			v[i]=der[iDer];
			iDer++;
			continue;
		}
		if(izq[iIzq]>der[iDer]){
			v[i]=der[iDer];
			iDer++;
			inv+=izq.size()-iIzq;
		}else{
			v[i]=izq[iIzq];
			iIzq++;
			
		}
	}
}

long long int getInv(vector<int> &v){
	long long int inv = 0;
	if(v.size()==1) return 0;
	vector<int> izq(v.begin(), v.begin() + v.size()/2);
	vector<int> der(v.begin() + v.size()/2 , v.end());
	inv += getInv(izq);
	inv += getInv(der);
	merge(v, izq, der,inv);
	return inv;
}

void solve(){
	int t;
	cin>>t;
	int n;
	vector<int> v;
	for(int i=0; i<t; i++){
		cin>>n;
		int value;
		for(int j=0; j<n; j++){
			cin>>value;
			v.push_back(value);
		}
		cout<<getInv(v)<<'\n';
		v.clear();
	}
}

int main(){
	ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
	solve();
	return 0;
}