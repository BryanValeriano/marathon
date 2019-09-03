#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define MAXN 1000100

typedef long long ll;

ll dp[MAXN];
ll pilha[MAXN][2];
int n;

bool compareResist(const pair<int, int>&i, const pair<int, int>&j)
{
    return i.second < j.second;
}

bool comparePeso(const pair<int, int>&i, const pair<int, int>&j)
{
    return i.first > j.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    
    vector< pair<int, int> > caixasA;
    vector< pair<int, int> > caixasB;
    int caixas1, caixas2;

    for(int i = 0; i < n; i++)
    {
        cin >> caixas1 >> caixas2;
        caixas2 -= caixas1;
        caixasA.pb(mk(caixas1,caixas2));
        caixasB.pb(mk(caixas1,caixas2));
    }
   
    memset(dp, 0, sizeof(dp));
    

    sort(caixasA.begin(), caixasA.end(), compareResist);  
    sort(caixasB.begin(), caixasB.end(), comparePeso);   
    
    for(int i = 0; i < caixasA.size(); i++)
    {
        cout << caixasA[i].fi << " - " << caixasA[i].sec << endl;
    }

    return 0;
}
