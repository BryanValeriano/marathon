#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 5e5;
const int T = 4 * N + 10;
vector<int> st(N, 0);
vector<tuple<int, int, int, int>> lazy(T);

vector<vector<int>> bytes;

void prop(int id, int l, int r) {

}

void update(int id, int l, int r, int b, int pos) {

}

int query(int id, int l, int r, int p) {
    prop(id, l, r);
    if (l == r) return st[l];
    int mid = (r + l) >> 1;
    return mid <= p ? query(id << 1, l, mid, p) : query(id << 1 | 1, mid + 1, r, p);
}

int n, a[N];
int root[N], nodes, L[M], R[M], seg[M];
 
int build (int l, int r) {
	int at = ++nodes;
 
	if (l == r) {
		seg[at] = a[at];
	} else {
		int m = (l + r)/2;
		L[at] = build (l, m);
		R[at] = build (m + 1, r);
		seg[at] = seg[L[at]] + seg[R[at]];
	}
 
	return at;
}
 
/* point update, v[p]++ */
int update (int i, int l, int r, int p) {
	int at = ++nodes;
 
	if (l == r) {
		seg[at] = seg[i] + 1;
	} else {
		int m = (l + r)/2;
		if (p <= m) {
			L[at] = update (L[i], l, m, p);
			R[at] = R[i];
		} else {
			L[at] = L[i];
			R[at] = update (R[i], m + 1, r, p);
		}
		seg[at] = seg[L[at]] + seg[R[at]];
	}
 
	return at;
}
 
/* range query: v[A] + ... + v[B] */
int A, B;
int query (int i, int l, int r) {
	if (A > B)	return 0;
	if (r < A or l > B)	return 0;
 
 	if (l >= A and r <= B) {
		return seg[i];
	} else {
		int m = (l + r)/2;
		return query (L[i], l, m) + query (R[i], m + 1, r);
	}
}


int main() {
    ios_base::sync_with_stdio(false);

    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0;i < m;i++) {
        int x;
        cin >> x;
        vector<int> bs(x);
        for (int j = 0;j < x;j++) cin >> bs[i];
        bytes.push_back(bs);
        dels.push_back(0);
    }
    int op, a, b, c;
    //seg do tempo 2 como base e colocar algo nela
    //root[10] = update(root[2],1,n,pos)
    for (int i = 0;i < q;i++) {
        cin >> op;
        if (op == 1) {
            cin >> a >> b;
            update(1, 0, n - 1, a - 1, b - 1);
        }
        else if (op == 2) {
            cin >> a;
            cout << query(1, 0, n - 1, a - 1) << endl;
        }
        else {
            cin >> a >> b >> c;
        }
    }
    return 0;
}

