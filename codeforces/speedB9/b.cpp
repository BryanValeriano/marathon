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

const int T = 20;
vector<ll> bag;
ll v[T];

void get(ll x, int casa, int f) {
    if(f > 3 or x > 1e18) return;
    if(casa == 19) { bag.pb(x); return; }
    for(ll i = 0; i <= (casa == 18? 1 : 9); i++) get(x + i*v[casa], casa+1, f + (i != 0));
}


int main() {
    ios_base::sync_with_stdio(false);
    v[0] = 1;
    for(int i = 1; i <= 18; i++) v[i] = (10ll * v[i-1]);
    get(0,0,0);
    sort(bag.begin(), bag.end());

    int tc; cin >> tc;
    while(tc--) {
        ll a,b;
        cin >> a >> b;
        int x = lower_bound(bag.begin(),bag.end(),a) - bag.begin();
        int y = lower_bound(bag.begin(),bag.end(),b+1) - bag.begin();
        x = bag.size() - x;
        y = bag.size() - y;
        cout << x-y << endl;
    }
    return 0;
}

