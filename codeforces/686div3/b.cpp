#include <bits/stdc++.h>
using namespace std;

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
vector<ii> v;

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        v.clear();
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            v.eb(x,i+1);
        }
        v.eb(-INF,-INF);
        v.eb(INF,INF);
        sort(v.begin(),v.end());
        int ans = -1;
        for(int i = 1; i < v.size()-1; i++) {
            if(v[i].fi != v[i-1].fi and v[i].fi != v[i+1].fi) {
                ans = v[i].se;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

