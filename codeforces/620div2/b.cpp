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

const int T = 105;
bool vis[T];
vector<string> bag;

int main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;

    vector<string> l;
    vector<string> r;
    vector<string> p;

    string ans;

    for(int i = 0; i < n; i++) {
        string x; cin >> x;
        bag.pb(x);
    }


    for(int i = 0; i < n; i++) {
        if(vis[i]) continue;
        string tmp = bag[i];
        reverse(tmp.begin(), tmp.end());
        for(int j = i+1; j < n; j++) {
            if(!vis[j] and tmp == bag[j]) {
                vis[i] = vis[j] = 1;
                l.pb(bag[i]);
                r.pb(bag[j]);
                break;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(vis[i]) continue;
        string tmp = bag[i];
        reverse(tmp.begin(), tmp.end());
        if(tmp == bag[i]) p.pb(bag[i]);
    }

    if(r.size()) reverse(r.begin(), r.end());

    for(auto x : l) ans += x;
    string tmp;
    for(auto x : p) if(x.size() > tmp.size()) tmp = x;
    if(tmp != "") ans += tmp;
    for(auto x : r) ans += x;

    cout << ans.size() << endl << ans << endl;

    return 0;
}

