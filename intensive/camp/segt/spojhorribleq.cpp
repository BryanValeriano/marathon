#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int T = 1e5;
ll seg[4*T + 1];
ll lazy[4*T + 1];
int a, b;

void propaga(int node, int i, int j) {
	seg[node] += lazy[node] * (j - i + 1);
	if(i != j) {
		lazy[2*node] += lazy[node];
		lazy[2*node+1] += lazy[node];
	}
	lazy[node] = 0;
}

ll update(int node, int i, int j, int val) {
	propaga(node, i, j);
	if(i > b or j < a) return 0;
	if(i >= a and j <= b) {
		lazy[node] += val;
		propaga(node, i, j);
		return seg[node];
	} else {
		int meio = (i+j) >> 1;
		ll R = update(2*node, i, meio, val); 
		ll L = update(2*node + 1, meio + 1, j, val);
		return  seg[node] = R + L;
	}
}

int main() {
    ios::sync_with_stdio(false);
	int tc; cin >> tc;
	while(tc--) {
		int n, k; cin >> n >> k;
		memset(seg, 0, sizeof seg);
		memset(lazy, 0, sizeof lazy);
		while(k--) {
			int op; cin >> op;
			if(op == 0) {
				int  val;
				cin >> a >> b >> val;
				a--; b--;
				update(1, 0, n-1, val);
				cout << a << " " << b << " " << val << endl;
				a = 0, b = n-1;
				cout << update(1, 0, n-1, 0) << endl;
			}
			else if(op == 1) {
				cin >> a >> b;
				a--; b--;
				cout << update(1, 0, n-1, 0) << endl;
			}
		}
	}
    return 0;
}

