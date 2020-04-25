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

int main() {
    ios_base::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vii v;
    vector<double> ans(n);

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v.eb(x,i);
    }

    sort(v.begin(),v.end());
    int used = 0;

    for(int i = n-2; i >= 0; i--) {
        ans[v[i].se] = v[i+1].fi - v[i].fi;
        v[i].fi = v[i+1].fi;
        used += ans[v[i].se];
    }

    if(used > m) { cout << -1 << endl; return 0; }
    m -= used;

    cout << fixed << setprecision(6);
    for(int i = 0; i < n; i++)
        cout << ans[i] + (double)m/n << endl;


    return 0;
}

