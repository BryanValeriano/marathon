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
typedef vector<vector<ll> >mat;

mat operator * (const mat &a, const mat &b) {
    mat m(3, vector<ll>(3,0));

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            for(int k = 0; k < 3; k++) {
                m[i][j] += (a[i][k] * b[k][j]) % MOD;
                m[i][j] %= MOD;
            }

    return m;
}

mat id() {
    mat m(3, vector<ll>(3,0));
    for(int i = 0; i < 3; i++) m[i][i] = 1;
    return m;
}

mat trans(int zero, int um, int dois) {
    mat m(3, vector<ll>(3,0));
    m[0][0] =  m[1][1] = m[2][2] = zero;
    m[0][1] = m[1][2] = m[2][0] = um;
    m[0][2] = m[1][0] = m[2][1] = dois;
    return m;
}

mat exp(ll e, ll zero, ll um, ll dois) {
    mat ans = id();
    mat ele = trans(zero, um, dois);

    while(e) {
        if(e&1) ans = ans * ele;
        ele = ele * ele;
        e >>= 1;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    ll n,l,r;
    cin >> n >> l >> r;

    ll nl = l;
    ll nr = r;
    ll div[3];

    for(int i = l; i <= r; i++)
        if(i % 3 == 0) { nl = i; break; }
    for(int i = r; i >= l; i--) 
        if(i % 3 == 2) { nr = i; break; }

    div[0] = div[1] = div[2] = (nr - (nl-1))/3;

    for(int i = l; i < nl; i++)
        if(l != nl) div[i%3]++;
    for(int i = r; i > nr; i--)
        if(r != nr) div[i%3]++;
    
    if(div[0] == div[1] and div[1] == div[2] and div[0] == 0)
        for(int i = l; i <= r; i++)
            div[i%3]++;

    mat m = exp(n-1, div[0], div[1], div[2]);

    ll ans = ((m[0][0] * div[0]) % MOD);
    ans += ((m[1][0] * div[1]) % MOD);
    ans %= MOD;
    ans += ((m[2][0] * div[2]) % MOD); 
    ans %= MOD;
    cout << ans << endl;

    return 0;
}

