#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
//typedef pair<int,int> ii;
//typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 7;
int g[T][T];
int mov[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
int n,m;

bool isIn(int i, int j) {
    return (i >= 0 and i < n and j >= 0 and j < m);
}

bool check() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            int ok = 0;
            for(int k = 0; k < 4; k++) {
                int ii = i+mov[k][0];
                int jj = j+mov[k][1];
                ok += (isIn(ii,jj) && (g[i][j] == g[ii][jj]));
            }
            if(ok > 1) return 0;
        }
    return 1;
}

int build(int i, int j) {
    if(j==m) i++, j = 0;
    if(i == n) return check();
    g[i][j] = 1;
    int ans = build(i,j+1);
    g[i][j] = 0;
    ans += build(i,j+1);
    return ans;
}

int solve(int i, int j) {
    n = i; m = j;
    return build(0,0);
}

int main() {
    //ios_base::sync_with_stdio(false);
    for(int i = 1; i < T; i++)
        for(int j = 1; j < T; j++)
            cout << i << " " << j << " = " << solve(i,j) << endl;
    return 0;
}

