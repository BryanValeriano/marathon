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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const ll MOD = 1e9 + 7;
const int n = 9;

typedef vector< vector<ll> > mat;

mat operator * (const mat &a, const mat &b) {
    mat m(n, vector<ll>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                m[i][j] = (m[i][j] + ((a[i][k] * b[k][j]) % MOD) ) % MOD;
    return m;
}

mat id() {
    mat m(n, vector<ll>(n));
    for(int i = 0; i < n; i++) m[i][i] = 1;
    return m;
}

mat trans() {
    mat m(n, vector<ll>(n));
	m = {
     {1, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
     {0, 0, 0, 1, 1, 1, 0, 0, 0, 0 },
     {0, 0, 0, 0, 0, 0, 1, 1, 1, 0 },
     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
     {0, 0, 0, 1, 1, 0, 0, 0, 0, 0 },
     {0, 0, 0, 0, 0, 0, 1, 1, 1, 0 },
     {1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
     {0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
     {0, 0, 0, 0, 0, 0, 1, 1, 1, 0 },
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    };

    return m;
}

ll exp(ll e) {
    mat ans = id();
    mat ele = trans();

    while(e) {
        if(e & 1) ans = ans * ele;
        ele = ele * ele;
        e >>= 1;
    }

    ll resp = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            resp = (resp + ans[i][j]) % MOD;

    return resp;
}

int main() {
    ios_base::sync_with_stdio(false);
    ll x; cin >> x;
    cout << exp(x-2) << endl;
    return 0;
}

