#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
    ios_base::sync_with_stdio(false);
    int n,m,t;
    while(cin >> n) {
        cin >> m >> t;
        int ans = 0;

        int ans2 = 0;
        int waste = t;

        if(n < m) swap(n,m);

        for(int i = 0; i*n <= t; i++) {
            int z = t-i*n;
            if(z % m == 0) ans = max(ans,i+z/m);
            else if(z % m < waste) ans2 = (i+z/m), waste = z%m;
            else if(z % m == waste) ans2 = max(ans2,i+z/m);
        }
        if(ans) cout << ans << endl;
        else cout << ans2 << " " << waste << endl;
    }


    return 0;
}

