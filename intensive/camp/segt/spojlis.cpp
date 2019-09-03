#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const long t = 3e4 + 3; 
int seg[4*t + 1];

void update(int node, int i, int j, int p, int val) {
	if(i > p or j < p) return;	
	if(i >= p and j <= p) seg[node] = val;
	else { 
		int meio = (i + j) >> 1;
		update(2*node, i, meio, p, val);
		update(2*node + 1, meio + 1, j, p, val);
		seg[node] = max(seg[2*node], seg[2*node + 1]);
	}
}

int query(int node, int i, int j, int a, int b) {
	if(i > b or j < a) return 0;
	if(i >= a and j <= b) return seg[node];
	int meio = (i + j) >> 1;
	return max(query(2*node, i, meio, a, b), query(2*node + 1, meio + 1, j, a, b));
}

int main() {
    ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<ll>ve;
	int v[t+3];
	for(int i = 0; i < n; i++) {
		cin >> v[i];	
		ve.pb(v[i]);
	}
	sort(ve.begin(), ve.end());
	ve.resize(unique(ve.begin(), ve.end()) - ve.begin());
	map<ll,int>ind;
	for(int i = 0; i < ve.size(); i++) {
			ind[ve[i]] = i+1;
	}
	for(int i = 0; i < n; i++) 
		v[i] = ind[v[i]];	
	int val;
	for(int i = 0; i < n; i++) {
		//cout << v[i] << endl;
		val = query(1, 0, t-1, 0, v[i] - 1);
		update(1, 0, t-1, v[i], val + 1);
	}
	cout << seg[1] << endl;
    return 0;
}

