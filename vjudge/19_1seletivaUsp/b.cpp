#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 1e5 + 10;
int pai[T];
int ans[T];
int peso[T];
int qa[T];
int qb[T];
bool vis[T];
vector<int> que;

void init() {
    for(int i = 0; i < T; i++) {
        pai[i] = i;
        peso[i] = 1;
    }
}

int find(int x) {
    return (x == pai[x]? x : pai[x] = find(pai[x]));
}

void join(int x, int y) {
    x = find(x);
    y = find(y);

    if(peso[x] < peso[y]) swap(x,y);

    pai[y] = x;
    peso[x] += peso[y];
}

int main() {
    ios::sync_with_stdio(false);
    init();
    int n, m, q, x;
    cin >> n >> m;
    for(int i = 0; i < m; i++) cin >> qa[i] >> qb[i];

    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> x;
        que.pb(x-1);
        vis[x-1] = 1;
    }

    int comps = n;

    for(int i = 0; i < m; i++) {
        if(!vis[i] and find(qa[i]) != find(qb[i])) {
            comps--;
            join(qa[i],qb[i]);
        }
    }

    for(int i = q-1; i >= 0; i--) {
        ans[i] = comps;
        if(find(qa[que[i]]) != find(qb[que[i]])) {
            comps--;
            join(qa[que[i]],qb[que[i]]);
        }
    }
    
    for(int i = 0; i < q; i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}

