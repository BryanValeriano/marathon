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
ll n;
ll v[3];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> v[0] >> v[1] >> v[2];
    if(n) n %= 4;
    ll ans = 1e18;
    for(ll i = 0; i < 10; i++)
        for(ll j = 0; j < 10; j++)
            for(ll k = 0; k < 10; k++) {
                if((n + i + 2*j + 3*k)%4) continue;
                ans = min(ans, i*v[0] + j*v[1] + k*v[2]);
            }
    cout << ans << endl;
    return 0;
}

