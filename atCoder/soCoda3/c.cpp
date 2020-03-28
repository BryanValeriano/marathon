#include <bits/stdc++.h>
using namespace std;
#define pb	push_back
const int INF = 0x3f3f3f3f;
const int T = 10;
const int N = 1e4+2;
int cost[T] = {0,2,5,5,4,5,6,3,7,6}, ok[T], dp[N], n, m;
vector<int> ans;

void build(int used) {
    if(used <= 0) return;
    int nxt;
    for(int i = 1; i <= 9; i++) {
        if(!ok[i] or used-cost[i] < 0) continue;
        if(dp[used-cost[i]] == dp[used]-1) nxt = i;
    }
    ans.pb(nxt);
    build(used-cost[nxt]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    memset(dp, -INF, sizeof dp);
    for(int i = 0; i < m; i++) { int x; cin >> x; ok[x] = 1; }
    dp[0] = 0;

    for(int i = 1; i < T; i++) {
        if(!ok[i]) continue;
        for(int j = 0; j+cost[i] <= n; j++)
            dp[j+cost[i]] = max(dp[j+cost[i]], dp[j]+1);
    }

    build(n);
    sort(ans.begin(),ans.end(), greater<int>());
    for(auto x : ans) cout << x;
    cout << endl;
    return 0;
}

