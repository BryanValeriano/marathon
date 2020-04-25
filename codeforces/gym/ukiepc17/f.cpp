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
const int T = 402;
double dp[T][T];
bool vis[T][T];

double solve(int tails, int turns) {
    if(!turns) return 0;
    if(vis[tails][turns]) return dp[tails][turns];
    vis[tails][turns] = 1;
    if(tails == 1) return dp[tails][turns] = 0.5;
    double l = (solve(tails-1,turns-1)+1)*0.5;
    double r = solve(tails,turns-1)*0.5;
    return dp[tails][turns] = l+r;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    cout << fixed << setprecision(6) << solve(n,k) << endl;
    return 0;
}
