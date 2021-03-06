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
const int T = 2e5+5;

const int p[2] = {31, 47};
const int m[2] = {1000000009, 1073807359};

ll p_pow[2][T], inv[2][T], h[2][T];
int n, d[T];
string s;

ll ele(ll b, ll e, ll mod) {
    ll ans = 1;
    while(e) {
        if(e&1) ans = (b*ans) % mod;
        b = (b*b) % mod;
        e >>= 1;
    }
    return ans;
}

void pre() {
    for(int j = 0; j < 2; j++) {
        p_pow[j][0] = 1;
        inv[j][0] = ele(p_pow[j][0], m[j]-2,m[j]);

        for (int i = 1; i < n; i++) {
            p_pow[j][i] = (p_pow[j][i-1] * p[j]) % m[j];
            inv[j][i] = ele(p_pow[j][i], m[j]-2,m[j]);
        }

        for (int i = 1; i < n; i++)
            h[j][i] = (h[j][i-1] + (s[i] - 'a' + 1) * p_pow[j][i]) % m[j];
    }
}

ii hsh(int a, int b) {
    ll ok1 = (h[0][b]-h[0][a-1]+m[0])%m[0];
    ok1 = (ok1 * inv[0][a-1]) % m[0];
    ll ok2 = (h[1][b]-h[1][a-1]+m[1])%m[1];
    ok2 = (ok2 * inv[1][a-1]) % m[1];
    return mk(ok1,ok2);
}

int solve() {
    set<ii> bag;

    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            bag.insert(hsh(i,i+k));
            k++;
        }
        d[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }

    return bag.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    s = "#"+s;
    n++;
    pre();
    cout << solve() << endl;
    return 0;
}
