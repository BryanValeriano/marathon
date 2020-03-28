#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vector<ll>> mat;

const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const ll MOD = 1e9 + 7;

ll n,m,k;
int q = 3;

mat operator * (const mat &a, const mat &b) {
    mat m(q,vector<ll>(q));
    for(int i = 0; i < q; i++)
        for(int j = 0; j < q; j++)
            for(int k = 0; k < q; k++) {
                m[i][j] += (a[i][k] * b[k][j]) % MOD;
                m[i][j] %= MOD;
            }
    return m;
}

mat id() {
    mat m(q,vector<ll>(q,0));
    for(int i = 0; i < q; i++) m[i][i] = 1;
    return m;
}

mat trans() {
    mat m(q,vector<ll>(q,0));
    m[0][0] = m[0][2] = 2;
    m[1][0] = m[2][2] = 1;
    return m;
}

ll expo(ll e) {
    mat ans = id();
    mat ele = trans();

    while(e) {
        if(e&1) ans = ans * ele;
        ele = ele * ele;
        e >>= 1;
    }

    return (k * ans[0][2]) % MOD;
}

ii check(ll qtd, bool need) {
    ll full = qtd*k;

    ll falta = m-full;
    ll grups = falta/(k-1);
    ll last = falta%(k-1);

    ll rest = n-full;

    //cout << full << " " << rest << " " << falta << " " << grups << " ";
    //cout << grups*k + (last? last : -1) << endl;

    bool ok = rest >= grups*k + (last? last : -1);
    ll ans = 0;
    if(need) ans = (expo(qtd) + falta) % MOD;

    return mk(ok,ans);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;

    ll l = 0;
    ll ans = n;
    ll r = n;

    while(l <= r) {
        ll mid = (l+r) >> 1;
        ii x = check(mid,0);
        if(x.fi) r = mid-1, ans = mid;
        else l = mid+1;
    }

    cout << check(ans,1).se << endl;
    return 0;
}

