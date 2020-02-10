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
const int INF = INT_MAX;
const double PI = acos(-1.0);

vector<int> trees, res;
set<int> used;
set<ii> corn;
int n;

void bota(int x) {
    used.insert(x);
    int a = INF, b = INF;
    int pos = lower_bound(trees.begin(), trees.end(), x) - trees.begin();
    if(pos < n) a = abs(x - trees[pos]);
    if(pos-1 >= 0) b = abs(x -trees[pos-1]);
    corn.emplace(min(a,b),x);
}

int main() {
    ios_base::sync_with_stdio(false);
    int m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        used.insert(x);
        trees.pb(x);
    }

    sort(trees.begin(), trees.end());

    for(auto t : trees) {
        if(!used.count(t-1) and !binary_search(trees.begin(), trees.end(), t-1)) {
            corn.emplace(1,t-1);
            used.insert(t-1);
        }
        if(!used.count(t+1) and !binary_search(trees.begin(), trees.end(), t+1)) {
            corn.emplace(1,t+1);
            used.insert(t+1);
        }
    }


    ll ans = 0;

    while(m--) {
        ii at = *corn.begin();
        corn.erase(at);
        ans += (ll)at.fi;
        int x = at.se;
        res.pb(x);
        if(!used.count(x-1)) bota(x-1);
        if(!used.count(x+1)) bota(x+1);
    }

    cout << ans << endl;
    for(auto x : res) cout << x << " ";
    cout << endl;
    return 0;
}

