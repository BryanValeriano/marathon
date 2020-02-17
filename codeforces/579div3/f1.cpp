#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back
#define int ll

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

void fu() {
    cout << "NO" << endl;
    exit(0);
}

bool cmp(const ii &a, const ii &b) {
    return a.fi - b.se > b.fi - a.se;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    int n,r; cin >> n >> r;
    vii pos;
    vii neg;

    for(int i = 0; i < n; i++) {
        int x,y;
        cin >> x >> y;
        if(y >= 0) pos.eb(x,y);
        else neg.eb(max(x,-y),y);
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end(), cmp);

    for(int i = 0; i < pos.size(); i++) {
        if(r < pos[i].fi) fu();
        else r += pos[i].se;
    }

    for(int i = 0; i < neg.size(); i++) {
        if(r < neg[i].fi) fu();
        else r += neg[i].se;
        if(r < 0) fu();
    }

    cout << "YES" << endl;

    return 0;
}
