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

ll mid;

bool bin(ll x) {
    ll l = 0;
    ll r = 1e6 + 5;

    while(l <= r) {
        mid = (l+r) >> 1;
        ll z = mid*mid*mid;
        if(z > x) r = mid-1;
        else if(z < x) l = mid+1;
        else return 1;
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc;
    while(tc--) {
        ll a,b;
        cin >> a >> b;

        if(bin(a*b) and (b%mid == 0) and (a%mid == 0)) cout << "Yes" << endl;

        else cout << "No" << endl;
    }
    return 0;
}

