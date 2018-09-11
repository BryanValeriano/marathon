#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
const int T = 3e4 + 3;
int seg[4*T + 1];

typedef long long ll;
const int INF = 0x3f3f3f3f;

struct node {
	int type;
	int val;
	int l;
	int r;
	int q_pos;
	int g_pos; 

	node(int type, int val, int l, int r, int q_pos, int g_pos) :
		type(type), val(val), l(l), r(r), q_pos(q_pos), g_pos(g_pos) {}

	bool operator < (const node &n) {
		if(val != n.val) return val > n.val;
		return type > n.type;
	}
};

void update(int node, int i, int j, int p, int val) {
	if(i > p or j < p) return;
	if(i >= p and j <= p) seg[node] += val; 
	else {
		int meio = (i+j)>>1;
		update(2*node, i, meio, p, val);
		update(2*node + 1, meio + 1, j, p, val);
		seg[node] = seg[2*node] + seg[2*node + 1];
	}
}

int query(int node, int i, int j, int a, int b) {
	if(i > b or j < a) return 0;
	if(i >= a and j <= b) return seg[node];
	int meio = (i + j) >> 1;
	return query(2*node, i, meio, a, b) + query(2*node + 1, meio + 1, j, a, b);
}

bool cmp(const pair<int,int>&a, const pair<int,int>&b) {
	return a.fi < b.fi;
}

int main() {
    //ios::sync_with_stdio(false);
	int n; scanf("%d", &n); //cin >> n
	int val;
	vector<node>row;
	for(int i = 0; i < n; i++) {
		scanf("%d", &val);; //cin >> val;
		row.pb(node(0, val, 0, 0, 0, i+1));
	}
	int q; cin >> q;
	int a, b, k;
	for(int i = 0; i < q; i++) {
		scanf("%d %d %d", &a, &b, &k);//cin >> a >> b >> k;
		row.pb(node(1, k, a, b, i, 0));
	}
	sort(row.begin(), row.end());
	vector< pair<int,int> >querys;
	for(auto id : row) {
		if(id.type == 0) {
			update(1, 0, n, id.g_pos, 1); 
		}
		else if(id.type == 1) {
			int val = query(1, 0, n, id.l, id.r);
			querys.pb(mk(id.q_pos, val));
		}
	}

	sort(querys.begin(), querys.end(), cmp);
	for(auto id : querys) 
		printf("%d\n", id.sec); //cout << querys[i].sec << endl;
    return 0;
}

