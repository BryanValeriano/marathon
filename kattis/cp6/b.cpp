#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef tuple<int,int,int> ti;
typedef vector<ii> vii;
typedef vector<ti> vti;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e4+2;
const int N = 505;

int dp[N][T];
int choose[N][T];
int n,c;
vti v;
vii tmp;

int solve(int at, int t) {
    if(at >= n) return 0;
    int &r = dp[at][t];
    if(r != -1) return r;
    r = 0;
    int a,b,d;
    tie(a,b,d) = v[at];
    r = max(r,solve(at+1,t));
    if(t + max(a,b) <= c) {
        int l = solve(at+1,t+b)+1;
        if(l > r) {
            r = l;
            choose[at][t] = 1;
        }
    }
    return r;
}

void build(int at, int t) {
    if(at >= n) return;
    int a,b,d;
    tie(a,b,d) = v[at];
    if(choose[at][t]) {
        cout << d << endl;
        build(at+1,t+b);
    } else build(at+1,t);
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp,-1,sizeof dp);
    cin >> n >> c;
    for(int i = 0; i < n; i++) {
        int d,s;
        cin >> d >> s;
        v.eb(d,s,i+1);
        tmp.eb(d,s);
    }
    sort(v.begin(),v.end(), [&] (ti a, ti b) {
        int x,y,w,z;
        tie(x,y,ignore) = a;
        tie(w,z,ignore) = b;
        if(x-y != w-z) return x-y > w-z;
        return false;
    });

    cout << solve(0,0) << endl;
    build(0,0);
    return 0;
}

