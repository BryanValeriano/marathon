#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int T = 1e5 + 3;
ll segt[4*T+1];
vector<int>row;

void build(int node, int i, int j) {
	if(i == j) segt[node] = row[i];
	else {
		int meio = (i+j) >> 1;
		build(2*node, i, meio);
		build(2*node + 1, meio + 1, j);
		segt[node] = segt[2*node] * segt[2*node+1];
	}
}

void update(int node, int i, int j, int p, int val) {
	if(i > p or j < p) return;
	if(i >= p and j <= p) segt[node] = val; 
	else {
		int meio = (i+j) >> 1;
		update(2*node, i, meio, p, val);
		update(2*node + 1, meio + 1, j, p, val);
		segt[node] = segt[2*node] * segt[2*node + 1];
	}
}

ll query(int node, int i, int j, int a, int b) {
	if(i > b or j < a) return 1;
	if(i >= a and j <= b) return segt[node];
	int meio = (i+j) >> 1;
	return query(2*node, i, meio, a, b) * query(2*node + 1, meio + 1, j, a, b);
}

int main() {
    ios::sync_with_stdio(false);
	int n, k;
	while(cin >> n >> k) {
		row.clear();
		memset(segt, 1, sizeof segt);
		int aux;
		for(int i = 0; i < n; i++) {
			cin >> aux;
			if(aux > 0) aux = 1;
			else if(aux < 0) aux = -1;
			row.pb(aux);
		}
		build(1, 0, n-1);
		while(k--) {
			char op;
			int a, b;
			cin >> op >> a >> b;
			if(op == 'C') {
				if(b > 0) b = 1;
				else if(b < 0) b = -1;
				update(1, 0, n-1, a-1, b);
			}
			else if(op == 'P') {
				ll val = query(1, 0, n-1, a-1, b-1);
				if(val == 0) cout << '0';
				else if(val < 0) cout << '-';
				else cout << '+';
			}
		}
		cout << endl;
	}	

    return 0;
}

