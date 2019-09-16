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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

ll n,m;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    double ans = 0;

    for(ll i = 1; i <= n; i++)
        ans += i * (pow((double)i/n,m) - pow((double)(i-1)/n,m));

    cout << fixed << setprecision(4) << ans << endl;
    return 0;
}

