#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
const int INF = 0x3f3f3f3f;
int maxx = -INF;
int n, a, b, c; 
int dp[4005];
vector<int> tam;

int bk(int seila, int pecas, int pos)
{
    if(seila > n) return -INF;
    if(dp[seila] != -1) return dp[seila];
    int maxx = -INF;
    int R, L;
    
    for(int i = pos; i < tam.size(); i++)
    {
        int tmp = tam[i];
        R = bk(seila + tmp, pecas + 1, pos);
        L = bk(seila, pecas, pos + 1);
        maxx = max(maxx, max(R, L));
    }
    
    dp[seila] = maxx;
    return pecas;
}

int main()
{
    cin >> n >> a >> b >> c;    
    tam.pb(a); tam.pb(b); tam.pb(c);
    sort(tam.begin(), tam.end());
    memset(dp, -1, sizeof dp);
    bk(0,0,0);

    cout << dp[n] << " " << n << endl;
    
    return 0;
}

