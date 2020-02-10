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

const int T = 3505;
int v[T];
int n,m,k;

int calc(int ini, int fim) {
    //cout << ini << " " << fim << endl;
    return max(v[ini],v[fim]);
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> m >> k;
        if(k >= m) k = m-1;

        int ans = 0;
        int ho = (n-m+1);

        for(int i = 0; i < n; i++) cin >> v[i];
        for(int j = 0; j <= k; j++) {
            int tmp = INF;
            //cout << j << " | " << n-(k-j) << endl;
            for(int i = j; i+ho-1 < n-(k-j); i++) tmp = min(tmp, calc(i,i+ho-1));
            ans = max(ans,tmp);
        }

        cout << ans << endl;
    }



    return 0;
}

