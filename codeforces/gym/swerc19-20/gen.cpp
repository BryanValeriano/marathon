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

    mt19937 rnd(std::chrono::system_clock::now().time_since_epoch().count());
    int n = 100000, m = 100000;
    uniform_int_distribution<int> gen(0, n - 1);
    set<ii> es;
    while (m) {
        int a = gen(rnd);
        int b = gen(rnd);
        if (a != b) {
            m -= es.emplace(a, b).second;
        }
    }
    cout << n << " " << m << " " << gen(rnd) << endl;
    for (auto& [x, y] : es) cout << x << " " << y << endl;
    return 0;
}

