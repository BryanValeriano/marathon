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

int n,m;
vii v;

bool check(int tam) {
    vii tmp;

    for(int i = 0; i <= tam; i++)
        tmp.pb(v[i]);
    
    sort(tmp.begin(), tmp.end(), [&] (const ii &x, const ii &y) {
        if(x.se != y.se) return x.se > y.se;
        return x.fi > y.fi;
    });

    for(int i = 0; i < tmp.size(); i++) 
        if(i + tmp[i].se > m) return false;

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    
    cin >> n >> m;
    int a,b;

    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        v.eb(b,a);
    }

    sort(v.begin(), v.end(), [&] (const ii &x, const ii&y) {
        if(x.fi != y.fi) return x.fi > y.fi;
        return x.se > y.se;
    });

    int l = 0;
    int r = n-1;
    int gol = -1;

    while(l <= r) {
        int mid = (l+r) >> 1;
        if(check(mid)) gol = mid, l = mid+1;
        else r = mid-1;
    }

    if(check(l)) gol = max(gol,l); 
    ll ans = 0;

    for(int i = 0; i <= gol; i++) ans += v[i].fi; 
    cout << ans << endl;

    return 0;
}

