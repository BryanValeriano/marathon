#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 1e9;
const double PI = acos(-1.0);

const int T = 1e5 + 5;
int v[T];
int v2[T];
int q[T];
int q2[T];
unordered_map<int,int> vv;
unordered_map<int, int> vv2;
unordered_map<int, int> ind;
vector<int> bag;
int n, m, a, b;

const int N = 1e6;
int seg[4*N+100][2];

void build(int node, int i, int j, int op) {
	if(i == j) {
		if(op == 0) {
			if(vv.count(i)) seg[node][op] = vv[i];
			else seg[node][op] = INF;
		} else {
			if(vv2.count(i)) seg[node][op] = vv2[i];
			else seg[node][op] = INF;
		}
	} else {
		int mid = (i+j) >> 1;
		build(2*node, i, mid, op);
		build(2*node+1, mid+1, j, op);
		seg[node][op] = min(seg[2*node][op], seg[2*node+1][op]);
	}
}

int query(int node, int i, int j, int op) {
	if(i > b or j < a) return INF;
	if(i >= a and j <= b) return seg[node][op];
	int mid = (i+j) >> 1;
	return min(query(2*node, i, mid, op), query(2*node+1, mid+1, j, op));
}

int main() {
    ios_base::sync_with_stdio(false);
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> v[i];
		bag.pb(v[i]);
	}
	for(int i = 0; i < n; i++) {
		cin >> v2[i];
		bag.pb(v2[i]);
	}

	cin >> m;
	for(int i = 0; i < m; i++) {
		cin >> q[i];
		bag.pb(q[i]);
	}
	for(int i = 0; i < m; i++) {
		cin >> q2[i];
		bag.pb(q2[i]);
	}

	sort(bag.begin(), bag.end());
	bag.resize(unique(bag.begin(), bag.end()) - bag.begin());
	
	for(int i = 0; i < bag.size(); i++) 
		ind[bag[i]] = i+1;

	for(int i = 0; i < n; i++) {
		if(!vv.count(ind[v[i]])) vv[ind[v[i]]] = i;
		if(!vv2.count(ind[v2[i]])) vv2[ind[v2[i]]] = i;
	}

	for(int i = 0; i < m; i++) {
		q[i] = ind[q[i]];
		q2[i] = ind[q2[i]];
	}

	build(1,0,N,0);
	build(1,0,N,1);

	b = N;
	for(int i = 0; i < m; i++) {
		a = q[i]+1;
		int x = query(1,0, N, 0);
		a = q2[i]+1;
		int y = query(1,0, N, 1);
		if(x < y) cout << "Mike" << endl;
		else if(y < x) cout << "Constantine" << endl;
		else cout << "Draw" << endl;
	}

    return 0;
}



