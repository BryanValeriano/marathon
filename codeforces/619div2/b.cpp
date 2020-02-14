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

const int T = 1e5 + 5;
int v[T];
int n;

ii check(int x) {
    int maxi = INF;
    int mini = 0;

    for(int i = 1; i < n; i++) {
        int tmini = mini;
        int tmaxi = maxi;

        if(v[i-1] == -1 and v[i] != -1) {
            tmini = max(0,v[i]-x);
            tmaxi = min(INF,v[i]+x);
            mini = max(mini,tmini);
            maxi = min(maxi,tmaxi);
        }
        else if(v[i] == -1 and v[i-1] != -1) {
            tmini = max(0,v[i-1]-x);
            tmaxi = min(INF,v[i-1]+x);
            mini = max(mini,tmini);
            maxi = min(maxi,tmaxi);
        }

        if(v[i] != -1 and v[i-1] != -1 and abs(v[i]-v[i-1]) > x) return mk(0,0);
        if(maxi < mini) return mk(0,0);
    }

    return mk(1,mini);

}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 0; i < n; i++) cin >> v[i];

        int l = 0;
        int r = 1e9;
        ii ans = mk(0,0);

        while(l <= r) {
            int mid = (l+r) >> 1;
            ii x = check(mid);
            if(x.fi) ans = mk(mid,x.se), r = mid-1;
            else l = mid+1;
        }

        cout << ans.fi << " " << ans.se << endl;
    }

    return 0;
}

