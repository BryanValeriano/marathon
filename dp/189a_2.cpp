#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
const int INF = 0x3f3f3f3f;
int maxx = -INF;
int n, a, b, c; 
int dp[4005][5];
vector<int> tam;

int bk(int tamanho, int pos)
{
    if(tamanho == n) return 0;
    if(tamanho > n) return -INF;
    if(pos > 2) return -INF;
    if(dp[tamanho][pos] != -1) return dp[tamanho][pos];
    
    int tmp = tam[pos];
    int R = 0;
    int L = 0;
    R = bk(tamanho + tmp,  pos) + 1;
    L = bk(tamanho, pos + 1);
    
    //cout << tamanho << ": " << dp[tamanho][pos]  << " pos:" << pos <<" pecas: " << pecas << endl;
    return dp[tamanho][pos] = max(R, L);
}

int main()
{
    cin >> n >> a >> b >> c;    
    tam.pb(a); tam.pb(b); tam.pb(c);
    sort(tam.begin(), tam.end());
    memset(dp, -1, sizeof dp);
    cout << bk(0,0) << endl;
    //cout << dp[0][0] << endl;
    
    return 0;
}

