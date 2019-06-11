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

const int T = 2e5 + 5;
int v[T];


int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;

    while(tc--) {
        int n,k;
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> v[i];
        int xx = INF;
        int ans = 0;
        for(int i = 0; i+k < n; i++) {
            int mid = (v[i] + v[i+k]) >> 1;
            int x = max(mid - v[i], v[i+k] - mid);
            if(x < xx) xx = x, ans = mid;
        }
        cout << ans << endl;    
   }


    return 0;
}

