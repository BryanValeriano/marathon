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

struct node {
    int t, id, f;

    bool operator < (const node &b) const {
        if(t != b.t) return t < b.t;
        return id < b.id;
    }
};

const int T = 1e3 + 2;
int ans[T];

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;

    while(tc--) {
        vector<node> v;

        int n; cin >> n;
        int l,r;

        for(int i = 0; i < n; i++) {
            cin >> l >> r;
            v.pb({l,i,r});
        }

        sort(v.begin(), v.end());

        int t = 0;
        
        for(int i = 0; i < n; i++) {
            t = max(t,v[i].t);
            if(v[i].f < t) { ans[v[i].id] = 0; continue; }
            ans[v[i].id] = t++;
        }

        for(int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}

