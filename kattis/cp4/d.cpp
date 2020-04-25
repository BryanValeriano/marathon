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
const int N = 21;
const int T = 12002;

int dp[N][T];
int choose[N][T];
int vis[N][T];
int v[N];
int tot,n,vez;

int solve(int at, int w) {
    if(at == n) return abs(w-(tot-w));
    if(vis[at][w] == vez) return dp[at][w];
    int l = solve(at+1,w);
    int r = solve(at+1,w+v[at]);
    if(l <= r) choose[at][w] = 0;
    else choose[at][w] = 1;
    vis[at][w] = vez;
    return dp[at][w] = min(l,r);
}

void build(int at, int w, int a, int b) {
    if(at == n) { cout << max(a,b) << " " << min(a,b) << endl; return; }
    if(choose[at][w]) build(at+1,w+v[at],a+v[at],b);
    else build(at+1,w,a,b+v[at]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    while(n) {
        tot = 0;
        for(int i = 0; i < n; i++) cin >> v[i], tot += v[i];
        vez++;
        solve(0,0);
        build(0,0,0,0);
        cin >> n;
    }
    return 0;
}

