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

const int T = 1e3 + 5;
int pont[T];
int par[T];
int d[T];
int mat[T][T];
int n;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    queue<int> fila;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < n-1; j++) cin >> mat[i][j];
        par[i] = mat[i][0];
        if(i == par[par[i]]) {
            fila.emplace(i), fila.emplace(par[i]);
            pont[i]++, pont[par[i]]++;
            d[i]++, d[par[i]]++;
        }
    }

    int ans = 0;
    
    while(!fila.empty()) {
        int i = fila.front();
        fila.pop();

        if(pont[i] >= n-1) continue;
        int nxt = mat[i][pont[i]];
        if(pont[nxt] >= n-1) continue;

        if(i == mat[nxt][pont[nxt]]) {
            int x = max(d[i]+1,d[nxt]+1);
            d[nxt] = d[i] = x;
            ans = max(ans,x);
            pont[i]++;
            fila.emplace(i);
            pont[nxt]++;
            fila.emplace(nxt);
        }

    } 

    bool ok = 1;
    for(int i = 1; i <= n; i++) ok &= (pont[i] == n-1);
    cout << (ok? ans : -1) << endl;

    return 0;
}

