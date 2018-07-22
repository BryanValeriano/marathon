#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
int maxnodes;
 
int triagem(int atual, int vezquepassa)
{
    int esquerda = atual * 2;
    int direita = esquerda + 1;
    if(esquerda < maxnodes && direita < maxnodes)
    {
        if(vezquepassa % 2 != 0) triagem(esquerda, (vezquepassa - 1)/2 + 1);
        else triagem(direita, vezquepassa/2);
    }
    else return atual;
}

int main()
{
    int tc, altura, rodada;
    cin >> tc;
    while(tc--)
    {
        cin >> altura >> rodada;
        maxnodes = pow(2, altura);
        cout << triagem(1, rodada) << endl;
    }
    
    return 0;
}

