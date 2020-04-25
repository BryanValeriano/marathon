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
ll a,b,x,y;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> a >> b >> x >> y;
    ll gcd = __gcd(x,y);
    x /= gcd;
    y /= gcd;

    ll ok = INF;
    ok = min(ok,a/x);
    ok = min(ok,b/y);
    cout << x*ok << " " << y*ok << endl;
    return 0;
}

