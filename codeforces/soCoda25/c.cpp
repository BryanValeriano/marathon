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
const int T = 1e4+2;
const int N = 102;
const int MOD = 1e9 + 7;
ll dp[N][T];
ll b[N][N];
int qtd[T];
int n;

void pre() {
    for(int i = 0; i <= n; i++) {
        b[i][0] = 1;
        b[i][i] = 1;
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            b[i][j] = (b[i-1][j-1] + b[i-1][j]) % MOD;
}


int main() {
    ios_base::sync_with_stdio(false);
    dp[0][0] = 1;
    cin >> n;
    pre();
    int x;

    for(int i = 0; i < n; i++) {
        cin >> x;
        qtd[x]++;
        for(int j = T-1; j-x >= 0; j--)
            for(int k = 0; k <= i+1; k++)
                if(dp[k][j-x]) dp[k+1][j] = (dp[k+1][j] + dp[k][j-x]) % MOD;
    }

    int ans = 0;
    int ok = 0;
    for(int i = 0; i < N; i++) {
        if(qtd[i]) ok++;
        for(int j = 1; j <= qtd[i]; j++)
            if(dp[j][j*i] == b[qtd[i]][j]) ans = max(ans,j);
    }

    cout << (ok <= 2? n : ans) << endl;

    return 0;
}

