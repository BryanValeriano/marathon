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
    int n,m;
    scanf("%d %d", &n, &m);

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
    int last = 0;

    while(!bag.empty()) {
        int u = bag.front(); 
        bag.pop();
        pai[u] = last;
        last = u;
        for(auto v : g[u]) {
            in[v]--;
            if(!in[v]) 
                bag.push(v);
        }
    }

    for(int i = 1; i <= n; i++) printf("%d\n", pai[i]); 

    return 0;
}

