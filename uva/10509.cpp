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

const int T = 1e6 + 3;
vector<ll> v(T);
double x;

bool check(double y) {
    return (y*y*y > x);
}

int main() {
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(4);
    cin >> x;
    while(x) {
        double l = 1;
        double r = 1e2 + 1;
        double eps = 1e-5;

        while(r-l > eps) {
            double mid = (l+r)/2;
            if(check(mid)) r = mid;
            else l = mid;
            cout << l << " " << r << endl;
        }

        cout << l << endl;
        cin >> x;
    }
    return 0;
}

