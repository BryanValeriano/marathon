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

int go(int atual, int tam)
{
    //empilhei uma possivel combinacao de tam caixas
    if(!tam) return 0;

    //cheguei ate a ultima caixa sem ter empilhado tam caixas
    if(atual >= n) return INF;

    //ja estive nessa posicao com (n - tam) caixas empilhadas
    //e sei qual o minimo de peso que pode ser empilhado
    if(dp[atual][tam] != -1) return dp[atual][tam];

    //nao pego a caixa da posicao atual
    int L = go(atual + 1, tam);

    //pego a caixa da posicao atual
    int R = go(atual + 1, tam - 1) + row[atua].fi;

    //se o peso minimo de empilhar (tam - atual) caixas
    // + peso da caixa atual
    //for maior que a resistencia da caixa atual,
    //nao eh possivel empilhar 
    if(row[atual].sec < R + row[atual].fi)
        R = INF;

    return min(R, L);
}

bool magic(const pair<int,int> &a, const pair<int,int> &b) 
{
    return a.se > b.se;
}

int main()
{
    int aux1, aux2, tc;
    cin >> n;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++)
    {
        cin >> aux1 >> aux2;
        row.pb(mk(aux1, aux2));
    }
    sort(row, row+n, magic);
    
    cout << go(0, 0, 0) << endl;    
    row.clear();
        
    return 0;
}

