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
        map<int,int>track;
        int aux;
        for(int i = 0; i < n; i++) {
            cin >> aux;
            track[aux]++;
        }
        ii ans = ii(INF,INF);
        for(auto x : track)  
            if(x.fi != 0 and k % x.fi == 0 and track.count(k/x.fi) and (x.fi != k/x.fi or track[x.fi] > 1))
                if(ans.fi > x.fi) ans = ii(x.fi, k/x.fi);
        if(ans.fi == INF) { cout << -1 << endl; continue; }
        cout << ans.fi << " " << ans.se << endl;
    }
    return 0;
}

