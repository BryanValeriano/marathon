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

const int T = 2e6 + 5;
string s,t;
int z[T];
vector<int> ans;

void ze() {
    int l = 0, r = 0;
    int n = s.size();
    int gol = t.size();
    memset(z, 0, sizeof z);

    for(int i = 1; i < n; i++) {
        if(i <= r) z[i] = min(z[i-l],r-i+1);
        while(z[i] + i < n and s[z[i]+i] == s[z[i]]) z[i]++;
        if(r < i + z[i] - 1) l = i, r = i+z[i]-1;
        if(z[i] == gol) ans.pb(i-gol); 
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        ans.clear();
        cin >> s >> t;
        s = t + "#" + s;
        ze();
        if(ans.size()) {
            cout << ans.size() << endl;
            for(auto x : ans) cout << x << " ";
            cout << endl;
        } else cout << "Not Found" << endl;
        if(tc) cout << endl;
    }
    return 0;
}

