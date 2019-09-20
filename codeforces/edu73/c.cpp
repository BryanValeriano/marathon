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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        ll a,b,c; cin >> a >> b >> c;
        ll mini = min({a,b,c});
        ll ans = 0;
        if(a == mini or b == mini) {
            cout << mini << endl;
        } else {
            a -= mini; b -= mini;
            ll sobra = 0;
            if(b > a) sobra += b-a, b = a;
            else sobra += a-b, a = b;
            if(sobra >= a) cout << mini+a << endl;
            else cout << mini + sobra + (a+b-sobra*2)/3 << endl;
            //cout << " Z " << mini << " " << sobra << " " << (a+b-sobra) << endl;
        }
    }


    return 0;
}

