#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'
#define int ll

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e5 + 2;
bool ans[T];
map<int,vector<int>> bag;

int32_t main() {
    ios_base::sync_with_stdio(false);
    int n,a,b;
    cin >> n >> a >> b;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        bag[x].pb(i);
    }

    while(bag.size()) {
        int at = bag.begin()->fi;

        if(bag.count(a-at)) {
            for(auto ok : bag[at]) ans[ok] = 0;
            for(auto ok : bag[a-at]) ans[ok] = 0;
            bag.erase(a-at);
        }

        else if(bag.count(b-at)) {
            for(auto ok : bag[at]) ans[ok] = 1;
            for(auto ok : bag[b-at]) ans[ok] = 1;
            bag.erase(b-at);
        }

        else { cout << "NO" << endl; return 0; }

        bag.erase(at);
    }

    cout << "YES" << endl;
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}
