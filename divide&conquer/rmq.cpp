#include <iostream>
#include <vector>

using namespace std;

typedef long long int Long;

const int oo = 1 << 30;

template<class T>
struct SegTree{

	SegTree *left, *right;
	T value;
	int l,r;

	SegTree(int L, int R):
		l(L), r(R), left(NULL), right(NULL), value(){}

	T build(vector<T>& Vo){
		if(l == r) return value = Vo[l & r];
		int h = (l + r) >> 1;
		left = new SegTree(l, h),
		right = new SegTree(h + 1, r);
		return value = left->build(Vo)
			+ right->build(Vo);
	}

	T query(int a, int b){
		if(r < a or b < l) return T();
		if(a <= l and r <= b) return value;
		return left->query(a, b) + right->query(a, b);
	}

};

struct MinInt{

	int v;

	MinInt(): v(oo){}

	MinInt(int V): v(V){}

	MinInt operator+(const MinInt& other) const{
		return MinInt(min(v, other.v));
	}

};

int main(){
	ios_base::sync_with_stdio(0),
	cout.tie(0), cin.tie(0);
	SegTree<MinInt> *st;
	int l,n,q,r;
	cin >> n;
	st = new SegTree<MinInt>(0, n - 1);
	vector<MinInt> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].v;
	st->build(v), cin >> q;
	for (int i = 0; i < q; i++)
		cin >> l >> r,
		cout << st->query(l, r).v << '\n';
	delete st;
	return 0;
}

