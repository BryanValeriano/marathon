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
const int T = 110;
int atk[T];
int def[T];

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        for(int i = 1; i <= n; i++) cin >> atk[i];
        for(int i = 1; i <= n; i++) cin >> def[i];
        atk[0] = atk[n]; def[0] = def[n];
        atk[n+1] = atk[1]; def[n+1] = def[1];
        int maxi = -1;
        for(int i = 1; i <= n; i++) 
            if(def[i] > atk[i-1] + atk[i+1])
                maxi = max(maxi, def[i]);
        cout << maxi << endl; 
    }
    return 0;
}

