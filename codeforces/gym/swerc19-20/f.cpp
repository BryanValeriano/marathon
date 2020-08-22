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

ll area(vector<pair<ll, ll>>& ps, int n) {
    ll sum = 0;
    for (int i = 1;i <= n;i++) {
        sum += ps[i - 1].fi * ps[i].se - ps[i - 1].se * ps[i].fi;
    }
    return abs(sum);
}

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 0;i < n;i++) {
        int p;
        cin >> p;
        vector<pair<ll, ll>> ps;
        ll x, y;
        for (int j = 0;j < p;j++) {
            cin >> x >> y;
            ps.emplace_back(x, y);
        }
        ps.push_back(ps[0]);
        ans += area(ps, p);
    }
    cout << ans / 2 << endl;
    return 0;
}

