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

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        ll n; cin >> n;
        string s; cin >> s;
        char c; cin >> c;
        ll ans = (n*(n+1LL))/2LL;
        ll cont = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] != c) cont++;
            else {
                if(cont != 0) ans -= (cont*(cont+1LL))/2LL;
                cont = 0;
            }
        }
        if(cont != 0) ans -= (cont*(cont+1LL))/2LL;
        cout << ans << endl;
    }
    return 0;
}

