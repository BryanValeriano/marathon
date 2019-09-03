#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int modulo = 1e9 + 7;
const int TAM = 1e5;
int dp[TAM + 5];
int k;

ll bk(int pos)
{
    if(pos == 0) return 1; 
    if(pos < 0) return 0; 
    if(dp[pos] != -1) return dp[pos];
    
    ll R = bk(pos - k);
    ll L = bk(pos - 1);

    dp[pos] = (R + L) % modulo;
    return dp[pos];
}
 
int main()
{
    int tc, a, b;
    cin >> tc;
    cin >> k;
    memset(dp, -1, sizeof dp);
    bk(TAM);
    dp[0] = 0;
    ll soma[TAM + 5];
    memset(soma, 0, sizeof soma);

    for(int i = 1; i <= TAM; i++)
       soma[i] = dp[i] + soma[i - 1]; 


    while(tc--)
    {
        scanf("%d", &a);
        scanf("%d", &b);
        cout << (soma[b] - soma[a - 1]) % modulo << endl;
    }

    
    return 0;
}

