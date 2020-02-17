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
typedef tuple<ll,ll,ll> tl;
typedef vector<tl> vtl;
const ll INF = 0x3f3f3f3f;
const int N = 52;
const int T = 1e5 + 2;

class TheProgrammingContestDivOne {
    public:

    ll dp[N][T];
    vtl v;
    int n, temp;

    TheProgrammingContestDivOne() {}

    static bool cmp(const tl &a, const tl &b) {
        ll a1,b1,c1,a2,b2,c2;
        tie(a1,b1,c1) = a;
        tie(a2,b2,c2) = b;
        return (b1*c2 > b2*c1);
    }

    ll solve(int at, int t) {
        if(at == n) return 0;
        if(dp[at][t] != -1) return dp[at][t];

        ll m,p,tt;
        tie(m,p,tt) = v[at];

        dp[at][t] = solve(at+1,t);
        if(t + tt <= temp) dp[at][t] = max(dp[at][t], solve(at+1,t+tt) + m - (t+tt)*p);
        return dp[at][t];
    }


    int find(int tt, vector<int>maxPoint, vector<int>pointsPerMinute, vector<int>requiredTime) {
        memset(dp, -1, sizeof dp);
        n = maxPoint.size();
        temp = tt;

        for(int i = 0; i < n; i++) {
            v.eb(maxPoint[i],pointsPerMinute[i],requiredTime[i]);
        }

        sort(v.begin(), v.end(), cmp);
        return solve(0,0);
    }
};
