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

ll p_pow[T];
ll h[T];
set<ll> bag[T];


void prefixHash(string const& s) {
    int n = s.size();
    p_pow[0] = 1;

    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % m;

    for (int i = 0; i < n; i++)
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
}

int n;
int insertHash(int l, int r) {
    ll cur_h = (h[r] + m - h[l-1]) % m;
    cur_h = (cur_h * p_pow[n-l-1]) % m;
    return bag[r-l+1].insert(cur_h).second;
}

int main() {
    ios_base::sync_with_stdio(false);

    string s;
    cin >> n >> s;
    s = "#"+s;
    prefixHash(s);

    vector<int> d(n, 0);
    int ans = 0;
    for (int i = 1, l = 0, r = -1;i < n;i++) {
        int k = i > r ? 1 : min(d[l + r - i], r - i + 1);
        while (0 <= i - k and i + k < n and s[i - k] == s[i + k]) {
            ans += insertHash(i - k, i + k);
            k++;
        }
        d[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    cout << ans << endl;
    return 0;
}

