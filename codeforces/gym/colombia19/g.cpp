#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define loop(x) for(int i = 0; i < x; i++)
#define each(x, xs) for(auto &x : xs)
#define endl '\n'
#define cc(x) cout <<#x <<" = " <<x <<endl

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 1e4 + 5;
int qtd[T];
int sem[T];
int in[T];
int sz[T];
int pai[T];
set<int> bag;
vector<int> g[T];
int n, k;

priority_queue<ii, vii> pq;

int dfs(int at) {
	int t = 1;
	for(int v : g[at]) t += dfs(v);
	sz[at] = t;
	return t;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;

	for(int i = 1; i <= n; i++) {
		int x; cin >> x;
		if(x == 0) continue;
		pai[i] = x;
		g[x].pb(i);
		in[i]++;
	}

	for(int i = 1; i <= n; i++)	{
		if(!in[i]) {
			dfs(i);
			pq.emplace(sz[i],i);
		}
	}

	for(int i = 1; i <= n+6; i++) bag.insert(i);
	int ans = 0;

	while(!pq.empty()) {
		ii wat = pq.top();
		pq.pop();
		int at = wat.se;
		int pos = sem[pai[at]];
		auto it = bag.lower_bound(pos+1);
		ans = max(ans,*it);
		sem[at] = *it;
		qtd[*it]++;

		if(qtd[*it] == k) bag.erase(*it);

		for(int v : g[at]) pq.emplace(sz[v],v);
	}

	cout << ans << endl;

	return 0;
}

