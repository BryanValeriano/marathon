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
const int T = 2e5+2;
const int N = 100;
int dp[2][N][T];
int n;

int solve(bool aberto, int fila, int t) {
    fila += v[i];
    if(fila > 87) return INF;
    if(!fila and t >= T) return 0;

    int &r = dp[aberto][fila][t];


}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp,-1,sizeof dp);
    cin >> n;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v[x]++;
    }
    for(int i = 1; i < T; i++) pre[i] += pre[i-1];

    cout << min(solve(0,0,0), solve(1,60,0)) << endl;
    return 0;
}

