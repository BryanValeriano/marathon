#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int TAM = 1e5+3;
int MOD = 1e9 + 7;
int M, N;
int dp[TAM][53];

int magic(int atual, int resto)
{
    if(atual < M || atual > N) return 0; 
    int &r = dp[atual][resto];
    if(r != -1) return r; 
    if(resto == 1) return 1;
    
    int R = magic(atual - 1, resto - 1) % MOD;
    int L = magic(atual + 1, resto - 1) % MOD;

    return r = (R + L) % MOD;
}

int main()
{
    int T;
    cin >> T >> M >> N;
    int resp = 0;
    memset(dp, -1, sizeof dp);
    for(int i = M; i <= N; i++)
        resp = (resp + magic(i, T)) % MOD;
    cout << resp << endl; 
    
    return 0;
}

