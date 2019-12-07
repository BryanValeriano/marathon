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

int n;
string s;
 
int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> s;
        int ans = n;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                ans = max(ans,(i+1)*2);
                ans = max(ans, (n-i)*2);
                ans = max(ans,n+1);
            }
        }
        cout << ans << endl;
    } 
    
    return 0;
}

