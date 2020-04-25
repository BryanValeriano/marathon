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
const ll MOD = 1e9 + 7;

void read(vector<string> &g, int n, int m) {
    for(int i = 0; i < n; i++) cin >> g[i];
}

bool isIn(int x, int y, int n, int m) {
    return(x >= 0 and x < n and y >= 0 and y < m);
}

int solve(const vector<string> &g, int n, int m) {
    vector<vector<int>> ans(n,vector<int>(m,0));
    int mov[2][2] = { {1,0},{0,1} };
    ans[n-1][m-1] = 1;

    for(int i = n-1; i >= 0; i--) {
        for(int j = m-1; j >= 0; j--) {
            if(g[i][j] == '#') continue;
            for(int k = 0; k < 2; k++) {
                int ii = i + mov[k][0];
                int jj = j + mov[k][1];
                if(isIn(ii,jj,n,m) and g[ii][jj] != '#')
                    ans[i][j] = (ans[i][j] + ans[ii][jj]) % MOD;
            }
        }
    }

    return ans[0][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<string> g(n);
    read(g,n,m);
    cout << solve(g,n,m) << endl;
    return 0;
}

