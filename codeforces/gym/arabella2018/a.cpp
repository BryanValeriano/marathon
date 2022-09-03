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
const ll LIM = 1e9;

void solve(ll tmp, bool ok) {
    ll casa = 1;
    int wat =  tmp > 0;
    ll wtf = 1;
    while(tmp) {
        ll rest = tmp%10;
        if(rest) {
            if(ok) cout << (wat? " + " : " - ");
            if(ok) cout << wtf*abs(rest) << " x " << casa;
            else cout << wtf*rest << " x " << casa;
            ok = 1;
        }
        casa *= 10ll;
        if(casa > LIM) wtf *= 10ll, casa /= 10ll;
        tmp /= 10;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        ll a,b; cin >> a >> b;
        ll tmp = a*b;
        solve(tmp,0);
        cout << endl;
    }
    return 0;
}

