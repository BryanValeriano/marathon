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

const int T = 2e5 + 10;
int v[T];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];
    int maxi = v[n-1];
    ll ans = maxi;
    for(int i = n-2; i >= 0; i--) {
        if(v[i] < maxi) {
            ans += v[i];
            maxi = v[i];
        } else if(maxi-1 >= 0) {
            ans += maxi-1;
            maxi--;
        } else break;
    }
    cout << ans << endl;
    return 0;
}

