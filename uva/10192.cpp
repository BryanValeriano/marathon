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

const int T = 105;

string a,b;
int dp[T][T];
int vis[T][T];
int v;

int solve(int x, int y) {
    if(x == a.size() or y == b.size()) return 0;
    if(vis[x][y] == v) return dp[x][y];

    if(a[x] == b[y]) return dp[x][y] = solve(x+1,y+1) + 1;
    dp[x][y] = max(solve(x+1,y), solve(x,y+1));

    vis[x][y] = v;
    return dp[x][y];
}

int bottom() {
    for(int j = 0; j <= b.length(); j++) dp[a.size()][j] = 0;

    for(int i = a.size() - 1; i >= 0; i--) {
        dp[i][b.size()] = 0;
        for(int j = b.size() - 1; j >= 0; j--) {
            if(a[i] == b[j]) dp[i][j] = 1 + dp[i+1][j+1];
            else dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
        }
    }

    return dp[0][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    getline(cin,a);
    int cont = 0;
    while(a[0] != '#') {
        getline(cin,b);
        v++;
        cout << "Case #" << ++cont << ": you can visit at most " << bottom() << " cities." << endl;
        getline(cin,a);
    }

    return 0;
}

