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
const int T = 1e5 + 10;
const int mod = 1e9 + 7;
int v[T];
ll k[T];

void ele(ll a, ll b) {
    k[0] = 0;
    k[1] = 2;
    for(int i = 2; i <= b; i++) {
        a = (a%mod) + (a%mod);
        a = (a%mod);
        k[i] = a;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n, q; cin >> n >> q;
    string s; cin >> s;
    v[0] = s[0] - '0';
    for(int i = 1; i < n; i++) 
        v[i] = (s[i] - '0') + v[i-1];
    int a, b;
    ele(2, 100004);
    for(int i = 0; i < q; i++) {
        cin >> a >> b;
        a--; b--;
        int ums = v[b] - (a - 1 >= 0? v[a-1] : 0);
        int zeros = ((b-a)+1)- ums;
        ll x;
        x = k[ums];
        ll sums = (x - 1) % mod;
        x = k[zeros];
        ll zums = sums*(x - 1) % mod;
        if(sums < 0) sums = 0;
        if(zums < 0) zums = 0;
        cout << (sums + (zeros != 0? zums : 0)) % mod << endl;
    }

    return 0;
}

