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
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
const ll INF = 1e11;
const double PI = acos(-1.0);
const int T = 1e5 + 2;

ll v[T];
int nxt[3][T];
int mins[3] = {1,90,1440};
ll cost[3] = {20,50,120};
ll ans[T];
ll dp[T];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    fill(dp,dp+T,INF);
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> v[i];
    v[n+1] = INF;

    for(int i = 0; i <= n; i++)
        for(int j = 1; j < 3; j++) {
            nxt[j][i] = min(n,(int)(lower_bound(v,v+n+1,v[i]+mins[j]) - v));
            if(v[nxt[j][i]] >= v[i] + mins[j]) nxt[j][i]--;
            nxt[j][i] = max(nxt[j][i],i);
        }

    dp[0] = 0;
    priority_queue<ii,vii,greater<ii>>pq;

    for(int i = 0; i <= n; i++) {
        ll at = INF;
        while(!pq.empty() and pq.top().se < i) pq.pop();
        if(!pq.empty()) at = pq.top().fi;

        dp[i] = min(dp[i],at);
        dp[i+1] = min(dp[i+1], dp[i]+20);
        pq.emplace(dp[i]+20,i+1);

        for(int j = 1; j < 3; j++) {
            dp[nxt[j][i+1]] = min(dp[nxt[j][i+1]], dp[i] + cost[j]);
            pq.emplace(dp[nxt[j][i+1]],nxt[j][i+1]);
        }
    }


    for(int i = 1; i <= n; i++)
        cout << dp[i]-dp[i-1] << endl;

    return 0;
}

