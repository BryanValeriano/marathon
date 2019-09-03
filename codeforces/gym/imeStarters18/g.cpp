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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 1e5 + 5;

double v[T];
double seg[4*T];
int a,b;
double val;

void build(int node, int i, int j) {
	if(i == j) seg[node] = v[i];
	else {
		int mid = (i+j) >> 1;
		build(2*node,i,mid);
		build(2*node+1,mid+1,j);
		seg[node] = (seg[2*node] + seg[2*node+1]);
	}
}

void update(int node, int i, int j) {
	if(i > b or j < a) return;
	if(i >= a and j <= b) seg[node] = val;
	else {
		int mid = (i+j) >> 1;
		update(2*node, i,mid);
		update(2*node+1, mid+1, j);
		seg[node] = seg[2*node] + seg[2*node+1];
	}
}

double query(int node, int i, int j) {
	if(i > b or j < a) return 0;
	if(i >= a and j <= b) return seg[node];
	int mid = (i+j) >> 1;
	return query(2*node,i,mid) + query(2*node+1,mid+1,j);
}
	
 
int main() {
    ios_base::sync_with_stdio(false);
	int n; cin >> n;
	double x;

	for(int i = 1; i <= n; i++) 
		cin >> v[i];

	build(1, 1, n);
int	q; cin >> q; 
	while(q--) {
		cin >> a >> b >> x;
		if(a == 1) {
			a = b;
			val = x;	
			update(1,1,n);
		} else {
			a = b;
			b = x;
			cout << fixed << setprecision(6) << query(1,1,n)/(b-a+1) << endl;
		}
	}

    return 0;
}

