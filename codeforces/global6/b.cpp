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
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        ll x; cin >> x;

        if(x < 15) cout << "NO" << endl;
        else {
            x %= 14;
            x += 14;
            if(x >= 15 and x <= 20) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}

