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

const int T = 102;
ll v[T];
int n;

int main() {
    ios::sync_with_stdio(false);

    ll mmc = 1;
    ll den = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        mmc = (mmc*v[i])/__gcd(mmc,v[i]);
    }

    for(int i = 0; i < n; i++) den += mmc/v[i];

    double ans = (double)mmc/(double)den;

    cout << fixed << setprecision(5) << ans << endl;

    return 0;
}

