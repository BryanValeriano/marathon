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

const int T = 102;
int v[T];
int n;
int r1,c1,r2,c2;

ii go(int linha, int col, int lg, int cg) {
    int passo;
    int ans = 0;

    if(linha < lg) passo = 1;
    else passo = -1;

    while(linha != lg) ans++, linha += passo, col = min(col,v[linha]);

    if(cg != -1) ans += abs(col-cg); 
    return mk(ans,col);
}

int main() {
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> v[i], v[i]++;
    cin >> r1 >> c1 >> r2 >> c2;

    int ans = INF;
    for(int i = 0; i < 100; i++) {
        if(r1+i <= n) {
            ii tmp = go(r1,c1,r1+i,-1);
            tmp.fi += go(r1+i,tmp.se,r2,c2).fi;
            ans = min(ans,tmp.fi);
        }
        if(r1-i >= 1) {
            ii tmp2 = go(r1,c1,r1-i,-1);
            tmp2.fi += go(r1-i,tmp2.se,r2,c2).fi;
            ans = min(ans,tmp2.fi);
        }
    }

    cout << ans << endl;

    return 0;
}

