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


bool ok(int x, int y) {
    double a = (double)x/(double)y;

    int xx = x%10;
    x /= 10;
    int yy = y%10;
    y /= 10;

    if(xx == x or yy == y) return 0;

    double b = (double)xx/(double)y;
    double c = (double)x/(double)yy;

    return((xx == y and c == a) or (x == yy and a == b));
}

void diff(int x, int y) {
    int xx = x%10;
    x /= 10;
    int yy = y%10;
    y /= 10;
    if(xx == y) cout << x << "/" << yy << endl;
    else cout << xx << "/" << y << endl;
}

int main() {
    ios_base::sync_with_stdio(false);

    ll ans1 = 1;
    ll ans2 = 1;
    for(int i = 1; i < 50; i++) {
        for(int j = 50; j < 100; j++) {
            if(ok(i,j)) {
                cout << i << "/" << j << " | ";
                diff(i,j);
                ans1 *= i/__gcd(i,j);
                ans2 *= j/__gcd(i,j);
            }
        }
    }

    cout << ans1 << " " << ans2 << endl;
    cout << ans2/__gcd(ans1,ans2) << endl;

    return 0;
}

