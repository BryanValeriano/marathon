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
        int a,b; cin >> a >> b;
        int x = abs(a-b);
        int ans = 0;
        ans += x/5;
        x -= (x/5)*5;
        ans += x/2;
        x -= (x/2)*2;
        ans += x;
        cout << ans << endl;
    }

    return 0;
}

