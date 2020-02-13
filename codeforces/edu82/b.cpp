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
        ll n,g,b;
        cin >> n >> g >> b;
        if(g >= (n/2 + (n&1)) or g >= b) cout << n << endl;
        else {
            ll good = (n/2) + (n&1);
            ll vezes = good / g;
            cout << max(n,vezes*(g+b) + (good%g? good%g : -b)) << endl;
        }
    }
    return 0;
}

