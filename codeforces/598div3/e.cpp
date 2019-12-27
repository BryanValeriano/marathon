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
const int T = 2e5 + 5;

int n;
int ans[T];
int best = 0;
vii v;

bool check(int t) {
    int mini = 2e9;
    int maxi = 0;
    int sz = 0;

    for(int i = 0; i < n; i++) {
        mini = min(v[i].fi,mini);
        maxi = max(v[i].fi,maxi);
        if(maxi - mini > t) {
            if(sz < 3) return 0;
            mini = v[i].fi;
            maxi = v[i].fi;
            sz = 0;
        }
        sz++;
    }

    return (sz >= 3);
}

void build(int t) {
    int mini = INF;;
    int maxi = 0;
    int sz = 0;
    int pos = 1;

    for(int i = 0; i < n; i++) {
        mini = min(v[i].fi,mini);
        maxi = max(v[i].fi,maxi);
        if(maxi - mini > t) {
            mini = v[i].fi;
            maxi = v[i].fi;
            sz = 0;
            pos++;
        }
        sz++;
        ans[v[i].se] = pos;
        best = max(best,maxi-mini);
    }

    cout << best << " " << pos << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v.eb(x,i);
    }

    sort(v.begin(), v.end());
    int l = 0;
    int r = 1e9;
    int z = r;

    while(l <= r) {
        int mid = (l+r) >> 1;
        if(check(mid)) z = mid, r = mid-1;
        else l = mid+1;
    }

    build(z);
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
    cout << check(7) << endl;

    return 0;
}

