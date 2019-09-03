#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")

#define pb push_back
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;

int trans[26][26];
int t[26][26];
int ind[130];
char s[26];

int dp[200][200][26];
int vis[200][200][26];
vii mov[26];

char v[200];
int x[200];
int n;
int vez;

inline int solve(int i, int j, int letra) {
    if(j - i == 0) return (x[i] == letra? 0 : INF);

    int &r = dp[i][j][letra];
    int &b = vis[i][j][letra];
    if(b == vez) return r;

    r = INF;
    b = vez;
    int ans;

    for(int k = i; k < j; k++) 
        for(auto z : mov[letra]) {
            ans = t[z.fi][z.se] + solve(i, k, z.fi) + solve(k+1, j, z.se); 
            if(ans < r) r = ans;
        }

    return r;
}

int main() {

    scanf("%d\n", &n);
    int q, ans, tmp, m;
    char letra;

    while(n) {
        for(int i = 0; i < n; i++) {
            scanf("%s", &s[i]), ind[s[i]] = i;
            mov[i].clear();
        }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                scanf("%d-%s", &t[i][j], &letra);
                trans[i][j] = ind[letra];
                mov[trans[i][j]].pb({i,j});
            }


        scanf("%d\n", &q);
        while(q--) {
            vez++;
            scanf("%s", v);
            m = strlen(v);
            for(int i = 0; i < m; i++) x[i] = ind[v[i]];
            ans = INF;
            for(int i = 0; i < n; i++) {
                tmp = solve(0,m-1,i);
                if(tmp < ans) ans = tmp, letra = s[i];
            }
            printf("%d-%c\n", ans, letra);
        }

        scanf("%d\n", &n);
        if(n) printf("\n");
    }
    return 0;
}

