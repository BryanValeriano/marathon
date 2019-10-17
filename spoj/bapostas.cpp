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
    while(n != 0) {
        ll ans = 0;
        ll x = 0;
        ll sum = 0;
        while(n--) {
            cin >> x;
            sum += x; 
            if(sum < 0) sum = 0;
            ans = max(ans,sum);
        }

        if(ans == 0) cout << "Losing streak." << endl;
        else cout << "The maximum winning streak is " << ans << "." << endl; 
        cin >> n;
    }
    
    return 0;
}

