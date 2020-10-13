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
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 2e3+3;
bool vis[T][T];
double dp[T][T];
double p[T],u[T];
int n,fa,fb;

double solve(int at, int a) {
    if(at >= 0) return 0;
    int b = fb-(at-(fa-a));
    vis[at][a] = 1;
    dp[at][a] = 0;
    if(a) dp[at][a] = max(dp[at][a], solve(at+1,a-1) + p[at]);
    if(b) dp[at][a] = max(dp[at][a], solve(at+1,a) + u[at]);
    if(a and b) dp[at][at] = max(dp[at][a], solve(

}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> fa >> fb;
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++) cin >> u[i];
    cout << solve(1,fa) << endl;
    return 0;
}

