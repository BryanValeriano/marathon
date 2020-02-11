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
        int n,k,x; cin >> n >> k;

        int mini = 0;
        int maxi = INF;
        int tmin,tmax;
        bool ans = 1;

        for(int i = 0; i < n; i++) {
            cin >> x;
            tmin = x-k;
            tmax = x+k;
            ans &= (tmin <= maxi and tmax >= mini);
            mini = max(mini,tmin);
            maxi = min(maxi,tmax);
        }
    
        cout << (ans? maxi : -1) << endl;
        
    }
    return 0;
}

