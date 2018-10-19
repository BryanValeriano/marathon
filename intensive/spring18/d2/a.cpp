#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int T = 43;
const int M = 64000 + 3;
int mat[T][T];
int memo[T][M];
int qtd[T];
int n;

int dp(int unit, int din, int casa) {
    if(casa < 0) return 0;
    if(unit == n) return 0;
    int &r = memo[unit][din];
    if(r !=  -1) return r;
    int m = 0;
    if(din >= mat[0][casa] && qtd[casa] >= unit) 
        m = dp(unit + 1, din - mat[0][casa], casa - 1) + mat[unit][casa];

    int t = 0;
    t = dp(unit, din, casa - 1);

    return r = max(m,t);
}

int main() {
    ios::sync_with_stdio(false);
    int din;
    cin >> n >> din;
    for(int i = 0; i < n; i++) 
        cin >> mat[0][i];
     
    int m;
    for(int i = 0; i < n; i++) {
        cin >> qtd[i];
        m = qtd[i];
        for(int j = 1; j <= m; j++) 
            mat[j][i] = mat[j-1][i];
    }
    for(int i = 1; i < n; i++) 
        for(int j = 1; j < n; j++) 
            mat[i][j] += mat[i][j-1];
   
    memset(memo,-1,sizeof memo);
    cout << dp(1, din, n-1) << endl;
    return 0;
}

