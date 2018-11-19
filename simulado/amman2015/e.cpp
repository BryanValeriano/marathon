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
int v[T];

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        int bonus = 100;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            bonus = min(bonus, 100 - v[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(v[i] + bonus >= 50) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}

