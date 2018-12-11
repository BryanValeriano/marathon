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
const int T = 1e3 + 10;
int pai[T];
int peso[T];

int find(int x) {
    return (pai[x] == x ? x : pai[x] = find(pai[x]));
}

void join(int x, int y) {
    x = find(x);
    y = find(y);

    if(x == y) return;

    if(peso[x] < peso[y]) swap(x,y);
    pai[y] = x;
    if(peso[x] == peso[y]) peso[x]++;
}

int main() {
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    set<ii> probs;
    set<int> pula;
    vii ans;
    int a,b;
    for(int i = 1; i <= n; i++) pai[i] = i;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        probs.insert(mk(a,b));
        probs.insert(mk(b,a));
        pula.insert(a);
        pula.insert(b);
    }
    int cont = 0;
    for(int i = 1; i <= n and cont < n-1; i++) {
        if(pula.count(i)) continue;
        for(int j = 1; j <= n and cont < n-1; j++) {
            if(i == j) continue;
            ii x = mk(i,j);
            ii y = mk(j,i);
            if(!probs.count(x) and !probs.count(y) /*and find(i) != find(j)*/) {
                cont++;
                //join(i,j);
                ans.pb(x);
                probs.insert(x);
                probs.insert(y);
            }
        }
    }
    cout << ans.size() << endl;
    for(auto x : ans) 
        cout << x.fi << " " << x.se << endl;
    return 0;
}

