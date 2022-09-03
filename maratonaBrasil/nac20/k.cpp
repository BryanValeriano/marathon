#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const ll MOD = 1e9+7;
const int K = 752;
const int N = 1e4+2;

ll table[K][K];
ll ans[K][N];
int k,n,z;

int busca(int key, int x, bool tipo) {
    int l = 0;
    int r = k-1;
    int res = -1;
    while(l <= r) {
        int mid = (l+r)>>1;
        if(!tipo) {
            if(table[key][mid] >= x) res = mid, r = mid-1;
            else l = mid+1;
        } else {
            if(table[key][mid] <= x) res = mid, l = mid+1;
            else r = mid-1;
        }
    }

    return res;
}

ii bb(int key, int l, int r) {
    int l2 = busca(key, l, 0);
    int r2 = busca(key, r, 1);
    return mk(l2,r2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> k >> z;
    for(int i = 0; i < k; i++)
        for(int j = 0; j < k; j++)
            cin >> table[i][j];

    ans[0][0] = 1;
    cin >> n;
    n--;

    for(int i = 1; i <= n; i++) {
        int p; cin >> p;
        for(int j = 1; j < k; j++) ans[j][i-1] = (ans[j][i-1] + ans[j-1][i-1] + MOD) %MOD;

        //cerr << i << " ---------------------\n";
        for(int j = 0; j < k; j++) {
            ii intervalo = bb(j, max(0, p-z), p+z);
            //cerr << j << " xxxxxxxxxx " << ans[j][i-1] << endl;
            //cerr << intervalo.fi << " " << intervalo.se << endl;
            if(intervalo.fi != -1 && intervalo.se != -1 && intervalo.fi <= intervalo.se) {
                ans[intervalo.fi][i] = (ans[intervalo.fi][i] + ans[j][i-1] + MOD)%MOD;
                ans[intervalo.se+1][i] = (ans[intervalo.se+1][i] - ans[j][i-1] + MOD)%MOD;
            }
        }
    }
    ll r = 0;
    for(int i = 0; i < k; i++) {
        if(i) ans[i][n] = (ans[i][n] + ans[i-1][n]) % MOD;
        r = (r + ans[i][n]) % MOD;
        //cerr << ans[i][n] << " o " << endl;
    }
    cout << r << endl;
    return 0;
}
