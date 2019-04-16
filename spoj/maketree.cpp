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

const int T = 1e5 + 5;
int in[T];
int pai[T];
vector<int> g[T];
 
int main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        int k; cin >> k;
        for(int j = 0; j < k; j++) {
            int p; cin >> p;
            in[p]++;
            g[i].pb(p);
        }
    }
    
    queue<int> bag;
    for(int i = 1; i <= n; i++) 
        if(!in[i]) bag.push(i);
  
    pai[bag.front()] = 0;
    int raiz = bag.front();
    int last = raiz;

    while(!bag.empty()) {
        int u = bag.front(); 
        bag.pop();
        if(pai[u] == 0 and u != raiz) pai[u] = last;
        for(auto v : g[u]) {
            in[v]--;
            if(!in[v]) {
                pai[v] = last;
                bag.push(v);
                last = v;
            }
        }
    }

    for(int i = 1; i <= n; i++) cout << pai[i] << endl;;

    return 0;
}

