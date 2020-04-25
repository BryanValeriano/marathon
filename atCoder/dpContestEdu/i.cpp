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

double solve(vector<vector<double>> &dp, vector<vector<bool>> &vis, const vector<double> &v, int h, int t, int n) {
    if(h+t == n) return (h > t);
    if(vis[h][t]) return dp[h][t];
    vis[h][t] = 1;
    dp[h][t] = (solve(dp,vis,v,h+1,t,n)*v[h+t] + solve(dp,vis,v,h,t+1,n)*(1-v[h+t]));
    return dp[h][t];
}


int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<double>> dp(n,vector<double>(n,0));
    vector<vector<bool>> vis(n,vector<bool>(n,0));
    vector<double> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << fixed << setprecision(9) << solve(dp,vis,v,0,0,n) << endl;
    return 0;
}

