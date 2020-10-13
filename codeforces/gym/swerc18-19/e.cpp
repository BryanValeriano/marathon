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
    vector<pair<string, int>> ps;
    string s;
    int x;
    cin >> n;
    int tot = 0;
    int z = 0;
    for (int i = 0;i < n;i++) {
        cin >> s >> x;
        ps.emplace_back(s, x * 100);
        tot += x * 100;
        if (!x) z++;
    }
    int lz = max(10049 - tot - 49 * n, 0);
    int lnz = max(10049 - tot - 49 * n, -50);
    int rz = min(10000 - tot + (n - z + 1) * 50, 49);
    int rnz = min(10000 - tot + (n - z) * 50, 49);
    if (lz > rz or lnz > rnz) cout << "IMPOSSIBLE" << endl;
    else {
        for (auto& [s, v] : ps) {
            int a = v + (v ? lnz : lz) , b = v + (v ? rnz : rz);
            cout << s << " ";
            cout << a / 100 << '.' << setw(2) << setfill('0') << a % 100 << " ";
            cout << b / 100 << '.' << setw(2) << setfill('0') << b % 100 << endl;
        }
    }
    return 0;
}

