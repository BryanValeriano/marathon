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
typedef pair<double, ii> node;

ll mat[50][50];
bool vis[50][50];
int n, m;
ll k;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    ll linha = 0;

    for(int j = 0; j < m; j++) {
        cin >> mat[0][j];
        linha += mat[0][j];
    }
    
    ll tot = 0;
    ll x = 0;
    ll ans = 0;
    sort(mat[0], mat[0] + m);

    for(int i = 1; i < n; i++) 
        for(int j = 0; j < m; j++) 
            mat[i][j] = mat[i-1][j];

    for(ll y = 0; y <= n; y++) {
        tot = x = 0;
        if(tot + y*linha <= k) {
            tot = y*linha;
            x = y*(m+1);
        } else break;
        for(int i = 0; i < m; i++) {
            for(int j = y; j < n; j++) {
                if(tot + mat[j][i] <= k) {
                    tot += mat[j][i];
                    x += 1LL;
                }
            }
        }
        ans = max(x,ans); 
    }
    
    cout << ans << endl;

    return 0;
}

