#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back
#define pop pop_back
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 22;

vector<int>g[T*T];
int id[T][T];
ii volta[T*T];
vector<int> caminho;
vector<int> tent;
int n, vez;
bool flag;
bool achou;
int cont;
bitset<T*T> mask;

void print() {
    cout << "Case #" << ++cont << ": POSSIBLE" << endl;
    for(int i = 0; i < caminho.size(); i++) 
        cout << volta[caminho[i]].fi << " " << volta[caminho[i]].se << endl;
}

void dfs(int u) {
    if(flag) return;
    mask[u] = 1;

    if(mask.count() == n) {
        flag = true;
        achou = true;
        print();
    }
    
    int c = 0;
    vector<int> gg = g[u];

    while(c < g[u].size()) {

        int t = rand() % gg.size();
        int v = gg[t];
        gg.erase(gg.begin() + t);
        c++;
        if(mask[v] == true) continue;

        caminho.pb(v);
        dfs(v);
        caminho.pop();

    }

    flag = true;
}

void init(int n) {
    mask.reset();
    for(int i = 0; i < T; i++) g[i].clear();
    tent.clear();
    for(int i = 0; i < n; i++) tent.pb(i);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        flag = 0;
        int r,c;
        cin >> r >> c;
        n = r*c;
        init(n);
        memset(id, 0, sizeof id);

        int x = 0;

        for(int i = 1; i <= r; i++) {
            for(int j = 1; j <= c; j++) {
                for(int k = 1; k <= r; k++) {
                    for(int p = 1; p <= c; p++) {
                        if(!id[k][p]) { id[k][p] = x++; volta[x-1] = mk(k,p); }
                        if(i != k and j != p and i+j != k+p and i-j != k-p)
                            g[id[i][j]].pb(id[k][p]);
                    }
                }
            }
        }

        achou = false;
        while(tent.size()) {
            int i =  rand()%tent.size();
            mask.reset();
            flag = false;
            dfs(tent[i]);
            tent.erase(tent.begin() + i);
        }

        if(!achou) cout << "Case #" << ++cont << ": IMPOSSIBLE" << endl;
    }
    return 0;
}

