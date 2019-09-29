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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

double solve(ll x) {
    if(x == 1) return 4;
    if(x == 2) return 4.5;
    if(x == 3) return 5;
    if(x == 4) return 2;
    return 1.5;
}

int main() {
    ios_base::sync_with_stdio(false);
    ll a,b; cin >> a >> b;
    double x = solve(a); x *= b;
    cout << fixed << setprecision(2) << "Total: R$ " << x << endl;
    return 0;
}

