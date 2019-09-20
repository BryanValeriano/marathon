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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 32;
ll dp[T][T][T];
char mat[T][T];
int n,m;

ll solve(int lin, int col, int lastR) {
    ll &r = dp[lin][col][lastR];
    if(r != -1) return r;
    if(col == m) return r = solve(lin+1,0,lastR);
    if(lin == n) return r = 1;

    if(mat[lin][col] != '.') {
        if(mat[lin][col] == 'B')
            return r = (lastR <= col? 0 : solve(lin,col+1,lastR));
        else
            return r = solve(lin,col+1,min(lastR,col));
    }

    ll x = 0;
    ll y = solve(lin,col+1, min(col,lastR));
    if(lastR > col) x = solve(lin,col+1,lastR);

    return r = x+y;
}



int main() {
    ios_base::sync_with_stdio(false);
    memset(dp,-1,sizeof dp);
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> mat[i][j];

    cout << solve(0,0,31) << endl;

    return 0;
}

