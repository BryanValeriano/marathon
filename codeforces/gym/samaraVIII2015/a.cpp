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

const int T = 1e4 + 5;
int dp[T][900][3];
int n,k;

struct node {
    int a,b,c;

    operator tuple<int,int,int>() {
        return make_tuple(a,b,c);
    }
};

vector<node> v;
int p[T], w[T], b[T];

int solve(int at, int peso, int uso) {
    if(peso > k) return -INF;
    if(at == n) return 0;
    int &r = dp[at][peso][uso];
    if(r != -1) return r;

    int ans = -INF;
    ans = solve(at+1, peso, uso);
    ans = max(ans, solve(at+1, peso + w[at], uso) + p[at]);
    if(uso < 2) ans = max(ans, solve(at+1, peso + w[at] - b[at], uso+1) + p[at]);

    return r = ans;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    int x,y,z;
    cin >> n >> k;
    k += 202;
    
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++) {
        cin >> x >> y >> z;
        v.pb({x,y,z});
    }

    sort(v.begin(), v.end(), [&] (const node &u, const node &t) {
        return (u.c != t.c)?  u.c > t.c : u.a > t.a;
    });
    
    for(int i = 0; i < n; i++) {
        tie(p[i],w[i],b[i]) = (tuple<int,int,int>)v[i];
    }

    cout << solve(0,202,0) << endl;
    
    return 0;
}

