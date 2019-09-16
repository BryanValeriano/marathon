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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
vector<ii> v;
map<ii,int> pos;
int n;

bool cmp(ii &a, ii &b) {
    if(a.fi != b.fi) return a.fi < b.fi;
    return a.se > b.se;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int a,b;cin >> a >> b;
        if(pos.count(mk(a,b))) {
            cout << pos[mk(a,b)] << " " << i << endl;
            return 0;
        }
        pos[mk(a,b)] = i;
        v.eb(a,b);
    }

    sort(v.begin(), v.end(), cmp);
    int r = 0;
    int p = 0;

    for(int i = 0; i < v.size(); i++) {
        if(v[i].se <= r) {
            cout << pos[v[i]] << " " << p << endl;
            return 0;
        }
        if(v[i].se > r) {
            p = pos[v[i]];
            r = v[i].se;
        }
    }

    cout << "-1 -1" << endl;
    return 0;
}

