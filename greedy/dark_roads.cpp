#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node{
    int x;
    int p;
};

struct Edge{
    int a;
    int b;
    int p;
};

bool operator<(Edge a, Edge b){
    return a.p > b.p;
}

const int MAX = 200001;
priority_queue<Edge> pq;
int tree[MAX];

void initRoots(int n){
    for(int i=0; i<n; i++){
        tree[i] = i;
    }
}

int getRaiz(int nod){
	if(tree[nod] == nod) return nod;
	return tree[nod] = getRaiz(tree[nod]);
}

bool isUnido(Edge edge){
    return (getRaiz(edge.a) == getRaiz(edge.b));
}

long long int kruskal(){
	long long int sum = 0;
    Edge edge;
    while(!pq.empty()){
        edge = pq.top();
        if(!isUnido(edge)){
            tree[getRaiz(edge.a)] = getRaiz(edge.b);
            sum+=edge.p;
        }
        pq.pop();
    }
    return sum;
}

void solve(){
	int n, m;
	int x, y ,z;
	int total;
	while(cin >> m >> n and (n!=0 || m!=0)){
		vector<Node> graph[MAX];
		total = 0;
		for(int i = 0; i < n; i++){
			cin >> x >> y >> z;
			graph[x].push_back({y,z});
        	graph[y].push_back({x,z});
        	pq.push({x,y,z});
        	total += z;
		}
		initRoots(n);
		cout << total - kruskal() << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
	solve();
	return 0;
}