#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;

int dp[105];

int max(int a, int b) {return (a > b)? a : b;}

int cutrod(int price[], int n)
{
    if(n == 0) return 0;
    if(dp[n] != 0) return dp[n];
    int q = 0;
    for(int i = 1; i <= n; i++)
    {
        q = max(q, price[i] + cutrod(price, n - i));
    }
    dp[n] = q;
    return q;
}
 
int main(){
    ios_base::sync_with_stdio(false);

    int t;
    int n;
    cin >> t;

    int price[100];

    for(int i = 0; i < t; i++)
    {
        cin >> n;
        for(int j = 1; j <= n; j++)
        {
            cin >> price[j];
        }
        memset(dp, 0, sizeof(dp));

        int profit = cutrod(price, n);
    
        cout << profit << endl;

    }

    return 0;
}

