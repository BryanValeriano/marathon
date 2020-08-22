#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
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
const int T = 11;

int solve(int n, int p, bool imp = true) {
    if (imp == (p & 1)) {
        return (p + 1) / 2;
    }
    int ans = n / 2 + (imp and n & 1);
    return ans + solve(n - ans, (p + 1) / 2, imp ^ (n & 1));
}

int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int i = 0;i < t;i++) {
        int n, p;
        cin >> n >> p;
        cout << solve(n, p) << endl;
    }
    return 0;
}

