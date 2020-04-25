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

int main() {
    ios_base::sync_with_stdio(false);
    double ans = 0;
    int n; cin >> n;
    while(n--) {
        int x; cin >> x;
        if(x < 2) ans += 2-x;
        else ans += 1.0/(double)x;
    }
    cout << fixed << setprecision(6) << ans << endl;
    return 0;
}

