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

const int p = 31;
const int m = 1e9 + 9;

ll p_pow[T], inv[T], h[T];
int n, d[T];
string s;

ll ele(ll b, ll e) {
    ll ans = 1;
    while(e) {
        if(e&1) ans = (b*ans) % m;
        b = (b*b) % m;
        e >>= 1;
    }
    return ans;
}

void pre() {
    p_pow[0] = 1;
    inv[0] = ele(p_pow[0], m-2);

    for (int i = 1; i < n; i++) {
        p_pow[i] = (p_pow[i-1] * p) % m;
        inv[i] = ele(p_pow[i], m-2);
    }

    for (int i = 1; i < n; i++)
        h[i] = (h[i-1] + (s[i] - 'a' + 1) * p_pow[i]) % m;
}

int hsh(int a, int b) {
    ll ok = (h[b]-h[a-1]+m)%m;
    ok = (ok * inv[a-1]) % m;
    return ok;
}

int solve() {
    set<int> bag[n];

    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            bag[k].insert(hsh(i-k,i+k));
            k++;
        }
        d[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }

    int ans = 0;
    for(int i = 1; i < n; i++) ans += bag[i].size();

    return ans;
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

