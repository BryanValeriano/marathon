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
const double EPS = 1e-7;
 
vector<int> a(4);

double area(double a, double b, double c) {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double f(double x) {
    return area(a[0], a[1], x) + area(a[2], a[3], x);
}

double ternary() {
    double l = max(abs(a[3]-a[2]), abs(a[0]-a[1])), r = min(a[2]+a[3], a[0] + a[1]);
    while(abs(l-r) >= EPS) {
        double del = (r - l) / 3.0;
        double x = l + del, y = r - del;
        double f1 = f(x);
        double f2 = f(y);
        if (f1-f2 <= EPS) l = x;
        if (f2-f1 <= EPS) r = y;
    }

    return f(l);
}

int main() {
    ios_base::sync_with_stdio(false);

    double ans = 0;
    for (int i = 0;i < 4;i++) cin >> a[i];
    sort(a.begin(), a.end());
    do {
        ans = max(ans, ternary());
    } while (next_permutation(a.begin(), a.end()));
    cout << fixed << setprecision(7) << ans << endl;   
    return 0;
}

