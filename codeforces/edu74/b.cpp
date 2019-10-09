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
int n,k;
vector<int> v;

bool check(int x) {
    ll ok = (ll)x*(ll)k;
    for(int i = 0; i < n-x; i++) {
        if(v[i] > ok) return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> k;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            v.pb(x);
        }

        sort(v.begin(),v.end());
        v.resize(unique(v.begin(),v.end()) - v.begin());
        n = v.size();

        int l = 0;
        int r = 1e5;
        int ans = r;

        while(l <= r) {
            int mid = (l+r) >> 1;
            if(check(mid)) r = mid-1, ans = mid;
            else l = mid+1;
        }

        cout << ans << endl;
        v.clear();
    }



    return 0;
}

