#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e6+2;
const int N = 4;
char mat[N][T];
bool help[N][N];
int mk[T];
int dp[2][(1<<6)];
bool can[(1<<9)][2];
int n,m;

int transition(int oldMask, int newMask) {
    newMask <<= (n<<(n-2));
    return oldMask|newMask;
}

int check(int col, int mask) {
    return __builtin_popcount((mk[col] ^ mask));
}

bool ok(int mask, bool corn) {
    corn &= n==3;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            help[i][j] = ((mask&(1<<(i*n+j))) > 0);

    int um;
    for(int i = 1+corn; i < n; i++) {
        for(int j = 1; j < n; j++) {
            um = 0;
            um = help[i][j] + help[i][j-1] + help[i-1][j] + help[i-1][j-1];
            if(!(um&1)) return 0;
        }
    }

    return 1;
}

int solve() {
    int ans = INF;

    for(int i = 0; i < (1<<(n*n)); i++)
        for(int j = 0; j < 2; j++)
            can[i][j] = ok(i,j);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(mat[i][j] == '1') mk[j] |= (1<<i);

    for(int newMask = 0; newMask < (1<<n); newMask++) {
        dp[0][(newMask<<(n==3?n:0))] = check(0,newMask);
        bitset<9> x = (newMask<<(n==3?n:0));
    }


    int at = 1;
    for(int col = 1; col < m; col++) {
        for(int oldMask = 0; oldMask < (1<<(n*(n-1))); oldMask++) {
            for(int newMask = 0; newMask < (1<<n); newMask++) {
                int tmp = transition(oldMask,newMask);
                if(can[tmp][col==1] and dp[!at][oldMask] != INF) {
                    int cost = check(col,newMask);
                    tmp >>= n;
                    dp[at][tmp] = min(dp[at][tmp],dp[!at][oldMask]+cost);
                    if(col==m-1) ans = min(ans,dp[at][tmp]);
                }
            }
        }

        for(int oldMask = 0; oldMask < (1<<(n*(n-1))); oldMask++)
            dp[!at][oldMask] = INF;

        at = !at;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp,INF,sizeof dp);

    cin >> n >> m;
    if((n >= 4 and m >= 4)) {
        cout << -1 << endl;
        return 0;
    }
    if(n==1 or m==1) {
        cout << 0 << endl;
        return 0;
    }

    bool corn = 0;
    if(n > m) corn = 1, swap(n,m);
    for(int i = 0; i < (corn? m : n); i++) {
        for(int j = 0; j < (corn? n : m); j++) {
            if(corn) cin >> mat[j][i];
            else cin >> mat[i][j];
        }
    }

    cout << solve() << endl;
    return 0;
}

