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

map<ii,int> g;
vector<int> v[T];
vector<int> corn[T];
int freq[T];
bool vis[T];

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;

    for(int i = 0; i < n-2; i++) {
        int a[3]; cin >> a[0] >> a[1] >> a[2];
        for(int j = 0; j < 3; j++) {
            freq[a[j]]++;
            for(int k = j+1; k < 3; k++) {
                g[mk(a[j],a[k])]++;
                g[mk(a[k],a[j])]++;

                
            }
        }
    }

    for(auto ok : g) {
        int j,k;
        j = ok.fi.fi;
        k = ok.fi.se;

        if(ok.se == 1) {
            corn[j].pb(k);
            corn[k].pb(j);
        }
        else if(ok.se == 2) {
            v[j].pb(k);
            v[k].pb(j);
        }
    }
    
    int ini = 0;
    int fim = 0;

    for(int i = 1; i <= n; i++) {
        if(freq[i] == 1) {
            if(ini == 0) ini = i;
            else fim = i;
        }
    }
    
    cout << ini << " ";
    vis[ini] = vis[fim] = 1;

    for(int i = 0; i < corn[ini].size(); i++) {
        bool flag = 0;
        for(int j = 0; j < corn[fim].size(); j++) 
            if(corn[ini][i] == corn[fim][j]) flag = 1;
        if(!flag) { ini = corn[ini][i]; break; }
    }

    int passo = 1;

    while(passo < n-1) {
        cout << ini << " ";
        vis[ini] = 1;

        for(int i = 0; i < v[ini].size(); i++) 
            if(!vis[v[ini][i]]) ini = v[ini][i];
        passo++;
    }
    
    cout << fim << endl;
    
    return 0;
}

