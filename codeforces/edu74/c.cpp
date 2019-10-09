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

const int T = 1e6;

vector<int> v;
unordered_set<int> ok;
bitset<T> out;
int dp[T][3];
int vis[T][3];
int vez;
int n;

int solve(int at, int dist) {
    if(at >= n) return 0;
    if(vis[at][dist] == vez) return dp[at][dist];

    int x = (dist == 1 and out[at]) or (dist == 2 and (!out[at]));
    x |= (dist == 2 and (!out[at-1]));
    int ans = INF;

    for(int i = 1; i <= 2; i++) ans = min(ans,solve(at+i,i)+x);

    vis[at][dist] = vez;
    return dp[at][dist] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int h; cin >> h >> n;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            ok.insert(x);
            v.pb(x);
            for(int j = 1; j <= 3 and x-j > 0; j++) v.pb(x-j);
        }

        sort(v.begin(),v.end());
        v.resize(unique(v.begin(),v.end()) - v.begin());
        sort(v.begin(),v.end(),greater<int>());
        for(int i = 0; i < v.size(); i++) {
            if(ok.count(v[i])) out[i] = 1;
            else out[i] = 0;
        }

        n = v.size();
        vez++;
        cout << solve(0,0) << endl;

        v.clear();
        ok.clear();
    }
    return 0;
}

