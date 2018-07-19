#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
int row[6];
int moedas[6] = {2,5,10,20,50,100};
int casas = 0; 
int dp[7][5005];

int go(int casa, int resto)
{
    if(resto < 0) return 0;
    if(resto == 0) return 1;
    if(casa >= 6) return 0;
    int &r = dp[casa][resto];
    if(r != -1) return r;

    int cont = 0;
    for(int i = 0; i <= row[casa]; i++)
    {
        cont += go(casa + 1, resto - i * moedas[casa]);
    }
    
    return r = cont;
}

int main()
{
    int S, aux;
    cin >> S;

    memset(dp, -1, sizeof dp);
    for(int i = 0; i < 6; i++)
    {
        cin >> aux;
        casas += aux; 
        row[i] = aux;
    }
  
    cout << go(0, S) << endl; 
    return 0;
}

