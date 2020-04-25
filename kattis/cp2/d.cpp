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
const int T = 1e3 + 2;

double dp[T][T];
int vis[T][T];
double prob[T+T];
int vez,n,m;

double solve(int x, int y) {
    if(x == n) return 0;
    if(y == m) return 1;
    if(vis[x][y] == vez) return dp[x][y];
    vis[x][y] = vez;
    return dp[x][y] = solve(x+1,y)*(1-prob[x+y]) + solve(x,y+1)*prob[x+y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n+m-1; i++) cin >> prob[i];
    vez++;
    cout << fixed << setprecision(6) << solve(0,0) << endl;
    return 0;
}

