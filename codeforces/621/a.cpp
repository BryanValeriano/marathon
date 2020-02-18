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
const int T = 105;
int v[T];
 
int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n,d;
        cin >> n >> d;
        int use = 0;
        int ans; cin >> ans;


        for(int i = 1; i < n; i++) {
            cin >> v[i];
            while(use+i <= d and v[i]) ans++, v[i]--, use += i;
        }

        cout << ans << endl; 

    }

    
    
    return 0;
}

