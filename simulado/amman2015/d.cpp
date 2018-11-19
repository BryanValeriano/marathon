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
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n, k;
        cin >> n >> k;
        string s; cin >> s;
        ll ans = 0;
        int pieces = (n/k);
        if(n%k != 0) pieces++;
        ans += (pieces - 1);
        for(int i = 0; i <= (n-k); i+=k) {
            bool flag = true;
            int cont = 0;
            for(int j = i+1; j < i+k && j < n; j++) {
                cont++;
                if(s[j] == s[j-1]) flag = false;
            }
            if(flag && cont > 1) ans += (k-1);
        }
        cout << ans << endl;
    }
    return 0;
}

