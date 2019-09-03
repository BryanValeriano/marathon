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
const int INF = 2e9;

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        ll ans = 0;
        int aux;
        for(int i = 0; i < n; i++) {
            cin >> aux;
            ans += aux-1;
        }
        cout << ans+1 << endl;
    }
    return 0;
}

