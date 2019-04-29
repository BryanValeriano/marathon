#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'

typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;

const int N = 2e5 + 10;

int tmp[N];
int peso[N];
vector<int> g[N];
int tin[N];
int tout[N];
int vis[N];
int volta[N];
int t, vez;
int n,a,b,val,id,ans;

struct Trie {
	map<bool,Trie> m;
    int cnt,word;

	Trie () {
		word = INF;
        cnt = 0;
		m.clear();
	}
};

Trie seg[4*N];

void add(const int &s, int i, Trie &Te) {
    Trie *T;
    T = &Te;

    while(i >= 0) {
        T->cnt++;
        bool valor = (s & (1 << i));

        if(!T->m.count(valor)) T->m[valor] = Trie();
        T = &T->m[valor];
        i--;
    }

    T->cnt++;
    T->word = min(T->word, id);
    return;
}

void search(const int &s, int i,  Trie &Te) {
    Trie *T;
    T = &Te;

    while(i >= 0) {
        bool valor = (s & (1 << i));

        if(T->m[!valor].cnt >= 1) {
            ans += (1<<i);
            T = &T->m[!valor];
        } else T = &T->m[valor];

        i--;
    }

    id = T->word; 
    return;
}


void build(int node, int i, int j) {
	if(i == j) {
		seg[node] = Trie();
        id = volta[i];
		add(peso[i],20,seg[node]);
	} else {
		int mid = (i+j) >> 1;
		build(2*node, i, mid);
		build(2*node+1, mid+1, j);

		seg[node] = Trie();
        for(int k = i; k <= j; k++) id = volta[k], add(peso[k], 20, seg[node]);
	}
}

ii best(const ii &a, const ii &b) {
    if(a.fi > b.fi) return a;
    if(b.fi > a.fi) return b;
    if(a.se < b.se) return a;
    return b;
}

ii query(int node, int i, int j) {
	if(i > b or j < a) return mk(0,INF);
	if(i >= a and j <= b) {
        ans = 0; 
        search(val,20, seg[node]);
        return mk(ans, id);
    }
	int mid = (i+j) >> 1;
	return best(query(2*node, i, mid), query(2*node+1, mid+1, j));
}

void dfs(int u) {
	vis[u] = vez;
	tin[u] = ++t;
	peso[tin[u]] = tmp[u];
    volta[tin[u]] = u;

	for(auto v : g[u])
		if(vis[v] != vez)
			dfs(v);

	tout[u] = t;
}

void init(int n) {
    for(int i = 1; i <= n; i++) g[i].clear();
}

int main(){

	int tc;
    scanf("%d\n", &tc);

	int q, x, y, lastval, lastnode;

	while(tc--) {

		lastval = 0, lastnode = 0;
		t = 0;

        scanf("%d %d\n", &n, &q);

		init(n);

		for(int i = 1; i <= n; i++) scanf("%d ", &tmp[i]);

		for(int i = 0; i < n-1; i++) {
            scanf("%d %d\n", &x, &y);
			g[x].pb(y);
			g[y].pb(x);
		} 

		vez++;
		dfs(1);
		build(1,1,n);

		while(q--) {

            scanf("%d %d\n", &x, &val);
			x ^= lastnode;
			val ^= lastval;

			a = tin[x];
			b = tout[x];
			ii h = query(1, 1, n);
            val = h.fi;
			x = h.se;

            printf("%d %d", x, val);

			lastnode = x;
			lastval = val;
		}
	} 

	return 0;
}



