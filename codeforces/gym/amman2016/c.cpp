#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'

typedef long long ll;
typedef pair<int,ll> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;

const int T = 1e5 + 10;
ii seg[4*T];
int a,b,val;

ii best(const ii &a, const ii &b) {
	if(a.se > b.se) return a;
	if(b.se > a.se) return b;
	if(a.fi < b.fi) return a;
	return b;
}

void build(int node, int i, int j) {
	if(i == j) seg[node] = ii(i,0);
	else {
		int mid = (i+j) >> 1;
		build(2*node, i, mid);
		build(2*node+1, mid+1, j);
		seg[node] = best(seg[2*node], seg[2*node+1]);
	}
}

void update(int node, int i, int j) {
	if(i > b or j < a) return;
	if(i >= a and j <= b) {
		seg[node].se += val;
	} else {
		int mid = (i+j) >> 1;
		update(2*node, i, mid);
		update(2*node+1, mid+1, j);
		seg[node] = best(seg[2*node], seg[2*node+1]);
	}
}

ii query(int node, int i, int j) {
	if(i > b or j < a) return ii(INF,-INF);
	if(i >= a and j <= b) return seg[node];
	int mid = (i+j) >> 1;
	return best(query(2*node, i, mid) , query(2*node+1, mid+1, j));
}

 
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	while(tc--) {
		int n, q;
		cin >> n >> q;
		build(1,1,n);
		int log = 1;
		int last = -1;
		for(int i = 1; i <= q; i++) {
			int x; cin >> x >> val;
			a = b = x;
			update(1,1,n);
			a = 1; b = n;
			ii tmp = query(1,1,n);
			if(tmp.fi != last) { log = i; last = tmp.fi; }
		}
		cout << (log == 1 and last == 1? 0 : log) << endl;
	} 
    return 0;
}

