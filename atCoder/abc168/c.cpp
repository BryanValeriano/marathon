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

double ang(ll h, ll m) {
    double x = h*30;
    if(m) x += ((double)m/60)*30;
    double y = m*6;
    x = abs(x-y);
    if(x > 180) x = 360-x;
    return x*(PI/180ll);
}

int main() {
    ios_base::sync_with_stdio(false);
    ll a,b,h,m;
    cin >> a >> b >> h >> m;
    double ans = sqrt(a*a + b*b - 2*b*a*cos(ang(h,m)));
    cout << fixed << setprecision(9) << ans << endl;
    return 0;
}

