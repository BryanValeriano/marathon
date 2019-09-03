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
const int T = 4e3 + 5;
const int N = 1e6 + 5;
int v[T];
vector<int> track[N];
vector<int> ve;
int n;
int dp[T][T];

inline int solve(int at, int a, int b, int round) {
    if(at >= n) return 0;

    int ans = 0;
    int &r = dp[a][b];
    if(r != -1) return r;

    if(round & 1) {
        at = lower_bound(track[a].begin(), track[a].end(), at+1) - track[a].begin();
        if(at < track[a].size()) at = track[a][at];
        else return 0;
    }
    else  {
        at = lower_bound(track[b].begin(), track[b].end(), at+1) - track[b].begin();
        if(at < track[b].size()) at = track[b][at];
        else return 0;
    }
    ans = solve(at, a, b, round+1) + 1;

    return r = ans;
}



int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        ve.pb(v[i]);
    }

    map<int,int> id;
    sort(ve.begin(), ve.end());
    ve.resize(unique(ve.begin(), ve.end()) - ve.begin());
    for(int i = 0; i < ve.size(); i++) id[ve[i]] = i;
    for(int i = 0; i < n; i++) v[i] = id[v[i]];

    for(int i = 0; i < n; i++) track[v[i]].pb(i);
    for(int i = 0; i < N; i++) sort(track[i].begin(), track[i].end());

    int ans = 1;
    for(int i = 0; i < n; i++) 
        for(int j = i+1; j < n; j++)
            ans = max(ans, solve(j, v[i],v[j], 1) + 2); 
    cout << ans << endl;
    return 0;
}

