#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef tuple<int,int,int> ti;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

bool equal(int pos, auto low, const vector<vector<int>> &v) {
    return (get<0>(*low) == v[pos][0] and get<1>(*low) == v[pos][1] and get<2>(*low) > pos);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        string s; cin >> s;
        s = '#' + s;

        vector<vector<int>> v;
        set<ti> prefix;
        for(int i = 0; i <= n; i++) v.pb(vector<int>(2,0));
        prefix.emplace(0,0,0);

        for(int i = 1; i <= n; i++) {
            if(s[i] == 'U') v[i][0]++;
            else if(s[i] == 'D') v[i][0]--;
            else if(s[i] == 'R') v[i][1]++;
            else v[i][1]--;
            v[i][0] += v[i-1][0];
            v[i][1] += v[i-1][1];
            prefix.emplace(v[i][0],v[i][1],i);
        }
        
        int ans = INF;
        int l = 1;
        int r = 1;

        for(int i = 1; i <= n; i++) {
            auto low = prefix.lower_bound(make_tuple(v[i-1][0], v[i-1][1], i));
            if(equal(i-1,low,v)) {
                if(get<2>(*low) - i < ans) {
                    ans = get<2>(*low) - i;
                    l = i, r = get<2>(*low);
                }
            }
        }

        if(ans == INF) cout << -1 << endl; 
        else cout << l << " " << r << endl;
    }
    return 0;
}

