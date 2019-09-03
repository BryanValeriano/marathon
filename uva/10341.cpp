#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const double euler = exp(1.0);
const double PI = acos(-1.0);
const double eps = 1e-9;
double p,q,r,s,t, u;

double f(double x) {
    return (p*pow(euler,-x) + q*sin(x) + r*cos(x) + s*tan(x) + t * pow(x,2) + u);
}

double solve() {
    double l = 0;
    double r = 1;
    while(r-l >= eps) { 
        double mid = (r + l)/2;
        if(f(mid) > 0) l = mid;
        else r = mid;
    }
    return (r+l)/2;
}

int main() {
    ios::sync_with_stdio(false);

    int pp, qq, rr, ss, tt, uu;
    while(cin >> pp) {
        cin >> qq >> rr >> ss >> tt >> uu;
        p = pp, q = qq, r = rr, s = ss, t = tt, u = uu;
        if(f(0) * f(1) <= 0) 
            cout << fixed << setprecision(4) << solve() << endl;
        else cout << "No solution" << endl;

    }

    return 0;
}

