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

const int T = 5e4 + 10;
const int N = 1e5;

int pai[T];
int peso[T];
vector<int> g[T];
vii arestas;

void init(n) {
    for(int i = 0; i <= n; i++) {
        pai[i] = i;
        peso[i] = 1;
        g[i].clear();
    }
    arestas.clear();

ll bin[N][3];

ll choose() { 
   for(int i = 0; i < N; i++) bin[i][0] = 1; 
   for(int j = 0; j <= 2; j++) bin[j][j] = 1;

   for(int i = 1; i < N; i++)
       for(int j = 1; j < i and j <= 2; j++)
            bin[i][j] = bin[i-1][j-1] + bin[i-1][j];
}

int main() {
    ios::sync_with_stdio(false);
    int m, u, v;
    cin >> m;
    choose();
    int z = 0;
    while(m) {
        int cont = 0;
        ll n = 0;
        init();
        for(int i = 0; i < m; i++) {
            cin >> u >> v;
        }
        if(ans == 0) { ans = 2; prod = bin[n][2]; }  
        cout << "Case " << ++z << ": " << ans << " " << prod << endl;
        stk[0] = 0;
        cin >> m; 
    }
    return 0;
}

