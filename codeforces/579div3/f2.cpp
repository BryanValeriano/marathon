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

void fu() {
    cout << "NO" << endl;
    exit(0);
}

bool cmp(const ii &a, const ii &b) {
    if(a.fi != b.fi) return a.fi > b.fi;
    return a.se > b.se;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    int n,r; cin >> n >> r;
    vii pos;
    vii neg;

    for(int i = 0; i < n; i++) {
        int x,y;
        cin >> x >> y;
        if(y >= 0) pos.eb(x,y);
        else neg.eb(x,y);
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end(), cmp);
    int ans = 0;

    for(int i = 0; i < pos.size(); i++) {
        if(r < pos[i].fi) break;
        else r += pos[i].se;
        ans++;
    }

    for(int i = 0; i < neg.size(); i++) {
        if(r < neg[i].fi) continue;
        else if(r < r += neg[i].se;
        if(r < 0) break;
        ans++;
    }
    
    cout << "YES" << endl;
    
    return 0;
}

