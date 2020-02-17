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

map<string, int> v;

int main() {
    ios_base::sync_with_stdio(false);
    int maxi = 0;
    int n; cin >> n;

    while(n--) {
        string s; cin >> s;
        v[s]++;
        maxi = max(maxi,v[s]);
    }

    vector<string> ans;
    for(auto x : v) if(x.se == maxi) ans.pb(x.fi);
    if(ans.size()) sort(ans.begin(), ans.end());
    for(auto x : ans) cout << x << endl;


    return 0;
}

