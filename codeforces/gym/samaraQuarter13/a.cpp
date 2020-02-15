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

const int T =2e5 + 5;
vector<int> v[T];
map<int,int> aa;
map<int,int> bb;
int n;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    if(n == 1) {
        cout << 1 << endl << 1 << endl;
        return 0;
    }

    for(int i = 0; i < n; i++) {
        int a,b,c; cin >> a >> b >> c;
        v[i].pb(a);
        v[i].pb(b);
        v[i].pb(c);
        sort(v[i].begin(), v[i].end());
        aa[v[i][0]]++;
        bb[v[i][1]]++;
    }

    vector<int> ans;

    for(int i = 0; i < n; i++) {
        aa[v[i][0]]--;
        bb[v[i][1]]--;

        if(aa[v[i][0]] == 0) aa.erase(v[i][0]);
        if(bb[v[i][1]] == 0) bb.erase(v[i][1]);

        ii x = *aa.rbegin();
        ii y = *bb.rbegin();

        if(v[i][1] > x.fi and v[i][2] > y.fi) ans.pb(i+1);

        aa[v[i][0]]++;
        bb[v[i][1]]++;
    }

    cout << ans.size() << endl;
    for(auto x : ans) cout << x << " ";
    cout << endl;
    
    return 0;
}

