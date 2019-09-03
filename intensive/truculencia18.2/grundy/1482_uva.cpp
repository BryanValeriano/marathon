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

set<ll> bag;

void pre() {
    bag.insert(0);
    bag.insert(1);
    for(ll i = 3; i <= 2e18; i += i+1) bag.insert(i);
}

int main() {
    ios::sync_with_stdio(false);
    pre();
    int tc; cin >> tc;
    while(tc--) {
        int n, x; cin >> n;
        int ans;
        for(int i = 0; i < n; i++) {
            cin >> x;
            if(i == 0) ans = !bag.count(x);
            else ans ^= !bag.count(x);
        }
        cout << (ans? "YES" : "NO") << endl;
        
    }
    return 0;
}

