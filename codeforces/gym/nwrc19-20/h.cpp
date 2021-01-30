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


int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int ok = 0;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        ok = max(v[i],ok);
        bag.insert(v[i]);
    }
    for(int x : bag) imp.pb(x);

    int q; cin >> q;
    for(int i = 0; i < q; i++) {
        int t; cin >> t;
        que.eb(t,i);
    }
    sort(que.begin(),que.end());

    int t = 0, r = 0;
    int last = 0;
    for(ii x : que) {
        if(x.fi < ok) {
            ans[x.se] = -1;
            continue;
        }
        if(imp[t] < x.fi-last) {
            last = proc(x.fi);
            if(t+1 < imp.size()

        }
        ans[x.se] = last;
    }

    return 0;
}

