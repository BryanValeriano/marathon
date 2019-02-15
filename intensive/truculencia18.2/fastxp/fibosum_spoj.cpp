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
const int MOD = 1e9 + 7;
const int n = 2;
typedef vector< vector<ll> > mat;

mat operator * (const mat &a, const mat &b) {
    mat m(n, vector<ll>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++) {
                m[i][j] += (a[i][k] * b[k][j]) % MOD;
                m[i][j] %= MOD;
            }
    return m;
}

mat id() {
    mat m(n, vector<ll>(n));
    for(int i = 0; i < n; i++) m[i][i] = 1LL;
    return m;
}

mat trans() {
    mat m(n, vector<ll>(n,1LL));
    m[1][1] = 0LL;
    return m;
}

ll expo(ll e) {
    mat ans = id();
    mat ele = trans();

    while(e) {
        if(e & 1) ans = ans * ele;
        ele = ele * ele;
        e >>= 1;
    }
    return ans[0][0];
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    ll a,b;
    while(tc--) {
        cin >> a >> b;
        a++; b++;
        ll ans = ((expo(b) - expo(a-1))+MOD) % MOD;
        cout << ans << endl; 
    }
    return 0;
}

