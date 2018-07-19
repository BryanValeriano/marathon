#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 3e3 + 3;
int n, size[N], cost[N];
int dp[N][N][3];

int funDP(int atual, int last, int qtd)
{
    if(qtd == 3) return 0;
    else if(atual > n) return INF;

    int rp = INF;
    
    if(dp[atual][last][qtd] != -1) return dp[atual][last][qtd];
    
    for(int i = atual; i < n; i++)
        if(size[i] > size[last])
        {
            rp = min(rp, funDP(i + 1, i, qtd + 1) + cost[i]);
        }
    
    dp[atual][last][qtd] = rp;
    return rp;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> size[i];
    for(int i = 0; i < n; i++)
        cin >> cost[i];
 
    memset(dp, -1, sizeof dp);
    int resp = INF; 

    for(int i = 0; i < n; i++)
        resp = min(resp, funDP(i + 1 , i, 1) + cost[i]);

    if(resp == INF) cout << -1 << endl;
    else cout << resp << endl;
    
    return 0;
}

