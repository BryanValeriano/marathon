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
    int n; cin >> n;

    int ans = 0;
    int maxi = 0;

    while(n--) {
        int x,y; cin >> x >> y;
        if(x > maxi) {
            ans = max(ans,y);
            maxi = x;
        }
    }

    cout << ans << endl; 
    
    return 0;
}

