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

    int n;
    cin >> n;
    map<string, int> cnt;
    string x;
    for (int i = 0;i < n;i++) {
        cin >> x;
        cnt[x]++;
    }
    vector<pair<string, int>> ans(cnt.begin(), cnt.end());
    sort(ans.begin(), ans.end(), [](pair<string, int> a, pair<string, int> b) {
        return a.se == b.se ? a.fi < b.fi : a.se > b.se;
    });
    cout << (ans[0].se > n / 2 ? ans[0].fi : "NONE") << endl;

    return 0;
}

