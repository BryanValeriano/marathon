#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,ll> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;

const int T = 1e5 + 5;

vector<int> palpite[T];
vector<int> npalpite[T];
vector<int> g[T];

int in[T];
int out[T];
int l[T];
int r[T];
int v[T];
int h[T];
ll lazy[4*T];
ll seg[4*T];
vii query;
int n,q,t,tam,a,b,val;
bool flag;

void dfs(int at) {
    in[at] = ++t;
    v[t] = at;

    for(int nxt : g[at]) dfs(nxt);

    out[at] = t;
}

void build(int node, int i, int j) {
    if(i == j) seg[node] = (flag? 1 : h[v[i]]);
    else {
        int mid = (i+j) >> 1;
        build(2*node,i,mid);
        build(2*node+1,mid+1,j);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
}

void prop(int node, int i, int j) {
    if(!lazy[node]) return;
    seg[node] += (j-i+1)*lazy[node];

    if(i != j) {
        lazy[2*node] += lazy[node];
        lazy[2*node+1] += lazy[node];
    }

    lazy[node] = 0;
}

void update(int node, int i, int j) {
    if(!flag) prop(node,i,j);
    if(i > b or j < a) return;

    if(i >= a and j <= b) {
        if(!flag) {
            lazy[node] += val;
            prop(node,i,j);
        } else seg[node]--;
        return;
    }

    int mid = (i+j) >> 1;

    update(2*node,i,mid);
    update(2*node+1,mid+1,j);
    seg[node] = seg[2*node] + seg[2*node+1];
}

ll que(int node, int i, int j) {
    if(!flag) prop(node,i,j);
    if(i > b or j < a) return 0;

    if(i >= a and j <= b) return seg[node];

    int mid = (i+j) >> 1;

    return que(2*node,i,mid) + que(2*node+1,mid+1,j);
}

void init() {
    memset(lazy, 0, sizeof lazy);
    build(1,1,n);
    for(int i = 0; i < tam; i++) {
        palpite[i] = npalpite[i];
        npalpite[i].clear();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    ll x, y, p;
    int op;
    t = -1;

    for(int i = 1; i <= n; i++) {
        cin >> h[i] >> x;
        g[x].pb(i);
    }

    cin >> q;

    for(int i = 0; i < q; i++) {
        cin >> op >> x;
        if(op == 1) {
            cin >> y;
            query.eb(x,y);
        } else {
            query.eb(-1,x);
            tam++;
        }
    }

    for(int i = 1; i <= n; i++) {
        r[i] = tam;
        palpite[(r[i] + l[i]) >> 1].pb(i);
    }

    dfs(0);
    build(1,1,n);

    for(int w = 0; w < 17; w++) {
        x = 0;

        for(int i = 0; i < q; i++) {
            if(query[i].fi == -1) {
                for(int j = 0; j < palpite[x].size(); j++) {
                    p = palpite[x][j];
                    a = b = p;
                    int mid = (l[p] + r[p]) >> 1;

                    if(que(1,1,n) <= 0) r[p] = mid;
                    else l[p] = mid + 1;

                    if(w == 16) npalpite[l[p]].pb(b);
                    else npalpite[ (l[p] + r[p]) >> 1].pb(p);
                }
                x++;
            } else {
                p = query[i].fi;
                val = -query[i].se;
                a = in[p]+1;
                b = out[p];
                if(a <= b) update(1,1,n);
            }
        }
        if(w == 16) flag = 1;
        init();
    }

    x = 0;

    for(int i = 0; i < q; i++) {
        if(query[i].fi == -1) {
            for(int j = 0; j < palpite[x].size(); j++) {
                a = b = palpite[x][j];
                update(1,1,n);
            }
            a = in[query[i].se]+1;
            b = out[query[i].se]; 
            cout << (a <= b? que(1,1,n) : 0) << endl;
            x++;
        }
    }
                
    return 0;
}

