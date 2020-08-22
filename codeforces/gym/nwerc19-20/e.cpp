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

    int a, b;
    char c;
    int sum = 0;
    vector<int> t;
    for (int i = 0;i < 4;i++) {
        cin >> a >> c >> b;
        t.push_back(100 * a + b);
        sum += t[i];
    }
    cin >> a >> c >> b;
    int trg = a * 100 + b;
    trg *= 3;
    sort(t.begin(), t.end());
    int x = trg - t[1] - t[2];
    if (sum - t[0] <= trg) cout << "infinite" << endl;
    else if ((t[0] > x or x < t[3]) and sum - t[3] > trg) cout << "impossible" << endl;
    else cout << fixed << setprecision(2) << x / 100.0 << endl;
    return 0;
}

