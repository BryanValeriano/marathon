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

int main() {
    ios_base::sync_with_stdio(false);
    freopen("dull.in", "r", stdin);

    int t;
    cin >> t;
    for (int i = 0;i < t;i++) {
        ll n, m, k;
        cin >> n >> m >> k;
        vector<ii> ps;
        int x, y;
        map<int, int> xtoi, ytoj;
        vector<int> itox(1, 0), jtoy(1, 0);
        for (int i = 0;i < k;i++) {
            cin >> x >> y;
            ps.emplace_back(x, y);
            xtoi[x];
            ytoj[y];
        }
        int aux = 0;
        for (auto& [k, v] : xtoi) v = ++aux, itox.push_back(k);
        aux = 0;
        for (auto& [k, v] : ytoj) v = ++aux, jtoy.push_back(k);
        int l = xtoi.size(), c = ytoj.size();
        itox.push_back(n + 1), jtoy.push_back(m + 1);

        vector<vector<int>> ch(l + 2, vector<int>(c + 2, 0));
        for (auto& [x, y] : ps) {
            ch[xtoi[x]][ytoj[y]] = 1;
        }
        for (int i = 1;i <= l;i++) for (int j = 1;j <= c;j++) {
            ch[i][j] += ch[i - 1][j] + ch[i][j - 1] - ch[i - 1][j - 1];
        }
        vector<int> lastx(c + 1, -1);
        ll ans = 0;
        for (int i = 1;i <= l;i++) {
            int lasty = -1;
            for (int j = 1;j <= c;j++) {
                if (ch[i][j] & 1) {
                    ll a = itox[i + 1] - itox[i];
                    ll b = jtoy[j + 1] - jtoy[j];
                    ans += a * b;
                }
            }
        }
        cout << ans << " " << n * m - ans << endl;
    }
    return 0;
}

