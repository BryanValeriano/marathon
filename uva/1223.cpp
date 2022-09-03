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
const int T = 5e3+5;
const ll p[2] = {31,47};
const ll m[2] = {1073807359, 1442968193};
ll po[2][T], inv[2][T], h[2][T];
set<pair<ll,ll>> bag;
int n;

void pre(string &s) {
    s = "#"+s;
    n = s.size();
    for(int j = 0; j < 2; j++) {
        po[j][0] = 1;

        for(int i = 1; i < n; i++)
            po[j][i] = (po[j][i-1] * p[j]) % m[j];

        for(int i = 1; i < n; i++)
            h[j][i] = (h[j][i-1]+(s[i]-'a'+1)*po[j][i])% m[j];
    }
}

int hsh(int l, int r, int c) {
    ll tmp = (h[c][r] - h[c][l-1] + m[c]) % m[c];
    tmp = (tmp * po[c][n-r]) % m[c];
    return tmp;
}

bool check(int k) {
    bag.clear();
    for(int i = k; i < n; i++) {
        ii tmp = mk(hsh(i-k+1, i, 0), hsh(i-k+1, i, 1));
        if(bag.count(tmp)) return 1;
        bag.insert(tmp);
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        string s; cin >> s;
        pre(s);
        int l = 0;
        int ans = 0;
        int r = s.size()-1;
        while(l <= r) {
            int mid = (l+r)>>1;
            if(check(mid)) l = mid+1, ans = mid;
            else r = mid-1;
        }
        cout << ans << endl;
    }
    return 0;
}

