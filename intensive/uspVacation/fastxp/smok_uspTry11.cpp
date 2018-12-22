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
int MOD = 1e9 + 7;
const int T = 110;
const int NIV = 1e3 + 10;
bool zero[T][T];
int n, k;

mat operator * (const mat &a, const mat &b) {
    mat x(n, vector<ll>(n,0LL));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++) {
                if(a[i][k] and b[k][j]) 
                x[i][j] += (a[i][k] * b[k][j]) % MOD;
                x[i][j] %= MOD;
            }
    return x;
}

mat id() {
    mat x(n, vector<ll>(n));
    for(int i = 0; i < n; i++) x[i][i] = 1;
    return x;
}

mat expo(ll e, mat ele) {
    mat ans = id();

    while(e) {
        if(e & 1) ans = ans * ele;
        ele = ele * ele;
        e >>= 1;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll l, u, v;
    cin >> n >> l >> k;

    mat m(n, vector<ll>(n));
    for(int i = 0; i < l; i++) {
        cin >> u >> v;
        u--; v--;
        m[u][v] += 1LL;
        m[v][u] += 1LL;
    }

    mat ans = expo(k, m);
    MOD = 1e9 + 11;
    mat ans2 = expo(k, m);
    
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++)
            cout << (ans[i][j] == 0 and ans[i][j] == ans2[i][j]? -1 : ans[i][j]) << " ";
        cout << endl;
    }

    return 0;
}

