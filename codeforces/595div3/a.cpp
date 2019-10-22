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
        int n; cin >> n;
        vector<int> v;
        while(n--) {
            int x; cin >> x;
            v.pb(x);
        }
        sort(v.begin(),v.end());
        int ans = 1;
        for(int i = 1; i < v.size(); i++) if(v[i] == v[i-1]+1) ans = 2;
        cout << ans << endl;
    }
        
    return 0;
}

