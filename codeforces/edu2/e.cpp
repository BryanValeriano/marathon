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
const int B = sqrt(T);
int t = 0;
vector<int> g[T];
vector< pair<ii, int> > q;
ll res[T];
ll maxi;
ll aux[T];
ll alt[T];
bool vis[T];
int cor[T];
int v[T];
int n;

void dfs(int atual) {
    vis[atual] = true;
    int tin = ++t;
    v[t] = cor[atual];
    for(int i = 0; i < g[atual].size(); i++) {
        int vizinho = g[atual][i];
        if(!vis[vizinho])
            dfs(vizinho);
    }
    int tout = t;
    q.pb(mk(mk(tin,tout), atual));
}

bool cmp(const pair<ii, int> &a, const pair<ii, int> &b) {
    ii x1, x2;
    x1 = a.fi;
    x2 = b.fi;
    if(x1.fi / B != x2.fi / B) return x1.fi / B < x2.fi / B;
    return x1.se > x2. se;
}

void tira(int i) {
    i = v[i];
    alt[aux[i]] -= i;
    aux[i]--;
    alt[aux[i]] += i;
    while(alt[maxi] == 0 and maxi > 0) maxi--; 
}

void add(int i) {
    i = v[i];
    alt[aux[i]] -= i;
    aux[i]++;
    alt[aux[i]] += i;
    if(aux[i] > maxi) maxi = aux[i]; 
}

void mo() {
    int l = 0, r = 0;
    
    for(int i = 0; i < q.size(); i++) {
        ii p = q[i].fi;
        int id = q[i].se;

        while(r < p.se) {
            r++;
            add(r);
        }
        while(r > p.se) {
            tira(r);
            r--;
        }
        while(l < p.fi) {
            tira(l);
            l++;
        }
        while(l > p.fi) {
            l--;
            add(l);
        }
        res[id] = alt[maxi];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int a, b;
    for(int i = 1; i <= n; i++)
        cin >> cor[i];
    for(int i = 0; i < n-1; i++) { 
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1);
    sort(q.begin(), q.end(), cmp);
    mo();
    for(int i = 1; i <= n; i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}

