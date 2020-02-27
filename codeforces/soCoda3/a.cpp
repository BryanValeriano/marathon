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
typedef tuple<int,int,int,int> ti;
typedef vector<ti> vti;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 100;
const int N = 2e3 + 10;
int dp[T][N];
int choose[T][N];

vti v;
vector<int> ans;
int n;

int solve(int at, int t) {
    if(at == n) return 0;
    int &r = dp[at][t];
    if(r != -1) return r;

    r = solve(at+1,t);

    int ti,di,pi,x;
    tie(ti,di,pi,x) = v[at];

    if(t + ti < di) {
        int l = solve(at+1,t+ti)+pi;
        if(l > r) r = l, choose[at][t] = 1;
    }

    return r;
}

bool cmp(const ti &a, const ti &b) {
    int ti,di,pi,xi;
    int tj,dj,pj,xj;

    tie(ti,di,pi,xi) = a;
    tie(tj,dj,pj,xj) = b;

    if(di != dj) return di < dj;
    else if(ti != tj) return ti < tj;
    return 0;
}

void build(int at, int t) {
    if(at == n) return;

    if(choose[at][t]) {
        ans.pb(get<3>(v[at]));
        build(at+1,t+get<0>(v[at]));
    } else {
        build(at+1,t);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp,-1,sizeof dp);
    cin >> n;

    for(int i = 0; i < n; i++) {
        int t,d,p;
        cin >> t >> d >> p;
        v.eb(t,d,p,i+1);
    }

    sort(v.begin(), v.end(),cmp);

    cout << solve(0,0) << endl;
    build(0,0);
    cout << ans.size() << endl;
    for(auto x : ans) cout << x << " ";
    cout << endl;

    return 0;
}

