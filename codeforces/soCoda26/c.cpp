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
const ll LIM = 10;

int main() {
    ios_base::sync_with_stdio(false);
    ll k,b,n,t;
    ll contD = 0;
    ll contB = 0;
    cin >> k >> b >> n >> t;

    ll z = 1;
    ll pass = 0;

    while(pass < n) {
        z = z*k+b, pass++;
        while(z > LIM) {
            contD += z/LIM;
            z /= LIM;
        }
    }

    ll ans = 0;
    while(t < z or contB < contD) {
        t = t*k+b, ans++;
        while(t > LIM) {
            contB += t/LIM;
            t /= LIM;
        }
    }

    cout << ans << endl;
    return 0;
}

