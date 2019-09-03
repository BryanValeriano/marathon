#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;

int numArestas;
ll matrix[256][256];
vector<ll> caminho;
vector<ll> resposta;
int sinal = 0;


bool check()
{
    if(caminho[0] == caminho[numArestas])
        return true;
    return false;
}

void hamilton(int node)
{
    if(sinal == 0)
    {
        if(caminho.size() == numArestas + 1 && check())
        {
            resposta = caminho;
            sinal = 1;
        }
        for(int i = 0; i < numArestas; i++)
        {
            if(matrix[node][i] != 0)
            {
                if(caminho.size() == 0) caminho.pb(node);
                caminho.pb(i);
                
                matrix[node][i] = 0;
                matrix[i][node] = 0;

                hamilton(i);
                
                matrix[node][i] = 1;
                matrix[i][node] = 1;

                caminho.pop_back();
            }
        }
    }
    else return;
}


int main()
{
    ll aresta, outra;
    string symbol;

    while(cin >> numArestas)
    {
        memset(matrix, 0, sizeof matrix);
        sinal = 0;
        while(cin >> symbol, symbol != "%")
        {
            aresta = stoi(symbol);
            aresta--;
            cin >> outra;
            outra--;
            matrix[aresta][outra] = 1;
            matrix[outra][aresta] = 1;

        }
        hamilton(0);
        if(resposta.size() != 0)
            for(int i = 0; i < resposta.size(); i++)
                cout << resposta[i] + 1 << " ";
        else cout << 'N' << endl;
        cout << endl;
    }
    return 0;
}

