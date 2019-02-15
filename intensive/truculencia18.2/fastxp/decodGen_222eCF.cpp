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
int n;

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

ll sumAll(const mat &m) {
    ll ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            ans += m[i][j];
            ans %= MOD;
        }
    return ans;
}

ll expo(mat ele, ll e) {
    mat ans = id();
    
    while(e) {
        if(e & 1) ans = ans * ele;
        ele = ele * ele; 
        e >>= 1;
    }

    return sumAll(ans);
}

int main() {
    ios::sync_with_stdio(false);
    ll p, k;
    cin >> p >> n >> k;
    mat m(n, vector<ll>(n,1LL));
    char u,v;
    int a,b;
    for(int i = 0; i < k; i++) {
        cin >> u >> v;
        if(u >= 'a' and u <= 'z') a = (u - 'a');
        else a = (u - 'A') + 26;
        if(v >= 'a' and v <= 'z') b = (v - 'a');
        else b = (v - 'A') + 26;
        m[a][b] = 0;
    }
    cout << expo(m, p-1) << endl;

    return 0;
}

