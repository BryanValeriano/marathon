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
const int T = 3e5+5;
int v[T];

bool maxWin(vii ve) {
    int ok = ve.back().se;
    for(int i = 0; i < ve.size(); i++) {
        if(ve[i].fi > ok) return 0;
    }
    return 1;
}

bool minWin(vii ve) {
    int ok = ve[0].fi;
    for(int i = 0; i < ve.size(); i++) {
        if(ve[i].se < ok) return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        int last = 0;
        int mini = INF;
        int maxi = 0;
        vii ve;

        for(int i = 0; i < n; i++) {
            cin >> v[i];
            if(v[i] > last) {
                mini = min(v[i],mini);
                maxi = max(v[i],maxi);
            } else {
                ve.eb(mini,maxi);
                mini = v[i];
                maxi = v[i];
            }
            last = v[i];
        }
        ve.eb(mini,maxi);
        cout << (maxWin(ve) or minWin(ve)? "YES\n" : "NO\n");
    }
    return 0;
}

