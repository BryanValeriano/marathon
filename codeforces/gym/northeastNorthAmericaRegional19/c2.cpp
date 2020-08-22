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

    int k, n;
    cin >> k >> n;
    vector<ll> a(n), acc(n + 1, 0);
    for (int i = 0;i < n;i++) {
        cin >> a[i];
        acc[i + 1] = a[i] + acc[i];
    }
    if (acc[n] % k) {
        cout << "NO" << endl;
        return 0;
    }
    ll x = acc[n] / k;
    map<int, int> last;
    vector<int> dep(n + 1, 0);
    bool ans = false;
    for (int i = 0;i <= n;i++) {
        last[acc[i]] = i;
        if (acc[i] >= x and last.count(acc[i] - x)) {
            dep[i] = dep[last[acc[i] - x]] + 1;
            if (dep[i] == k - 1) ans = true;
        }
    }
    cout << (ans ? "YES" : "NO") << endl;
    return 0;
}

