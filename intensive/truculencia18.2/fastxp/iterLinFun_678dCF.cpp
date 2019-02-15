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
typedef vector< vector<ll> > mat;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int n = 2;
ll a, b, p, x;

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
    for(int i = 0; i < n; i++) m[i][i] = 1;
    return m;
}

ll expo(mat ele, ll e) {
    mat ans = id();

    while(e) {
        if(e & 1) ans = ans * ele;
        ele = ele * ele;
        e >>= 1;
    }

    ll resp = (ans[0][0] * x) % MOD;
    resp += (ans[1][0] * b) % MOD;
    resp %= MOD;

    return resp;
}


int main() {
    ios::sync_with_stdio(false);
    cin >> a >> b >> p >> x;
    mat m(n, vector<ll>(n,1LL));
    m[0][0] = a;
    m[0][1] = 0;
    cout << expo(m, p) << endl;
    return 0;
}

