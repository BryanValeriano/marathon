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
    double n,k,d,s;
    cin >> n >> k >> d >> s;
    double ans = (n*d - s*k)/(n-k);
    if(ans > 100.000000 or ans < 0) cout << "impossible\n";
    else cout << fixed << setprecision(7) << ans << endl;
    return 0;
}

