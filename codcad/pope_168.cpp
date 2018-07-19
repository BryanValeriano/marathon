#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
 
vector< pair<int,int> > row;
int n;
int dp[1000][1000];
int resp;

int go(int qtd, int res, int i)
{
    cout << "qtd: " << qtd << " res: " << res << " pos: " << i << endl;
    if(res < 0) return qtd-1;
    if(i >= n) return qtd;
    if(dp[qtd][res] != -1) return dp[qtd][res];
    
    for(int pos = 0; pos < row.size(); pos++)
    {
        int novares;
        if(qtd > 0)
            novares = min(res - row[pos].fi, row[pos].sec - row[pos].fi);
        else
            novares = row[pos].sec - row[pos].fi;

        pair<int,int>tmp = row[pos];
        row.erase(row.begin() + pos);
        int R = go(qtd+1, novares, i);
        row.insert(row.begin() + pos, tmp);
        int L = go(qtd, res, ++i); 
        resp = max(R, max(L, resp));
    }

    return dp[qtd][res] = resp;
}

int main()
{
    int aux1, aux2;
    cin >> n;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++)
    {
        cin >> aux1 >> aux2;
        row.pb(mk(aux1, aux2));
    }

    cout << go(0, 0, 0) << endl;    
    
    return 0;
}

