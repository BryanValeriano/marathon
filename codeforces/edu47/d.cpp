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
    int n, m; cin >> n >> m;
    vii ans;

    for(int i = 1; i <= n and ans.size() < m; i++) {
        for(int j = i+1; j <= n and ans.size() < m; j++) {
            int gcd = __gcd(i,j);
            if(gcd == 1) ans.eb(i,j);
        }
    }

    if(ans.size() < m or m < n-1) cout << "Impossible" << endl;
    else {
        cout << "Possible" << endl;
        for(auto x : ans) cout << x.fi << " " << x.se << endl;
    }
    return 0;
}

