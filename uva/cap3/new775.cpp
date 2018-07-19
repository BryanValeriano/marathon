#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;

int numArestas;
int matrix[256][256];
vector<int> caminho;
vector<int> resposta;


bool check()
{
    if(caminho[0] == caminho[numArestas])
        return true;
    return false;
}

void hamilton(int node, int size)
{
    if(size == numArestas + 1 && check())
        resposta = caminho;

    for(int i = 0; i <= numArestas; i++)
    {
        if(matrix[node][i] != 0)
        {
            caminho.pb(matrix[node][i]);
            hamilton(i, size + 1);
            caminho.pop_back();
        }
    }
}


int main()
{
    int aresta, outra;
    string symbol;

    while(cin >> numArestas)
    {
        memset(matrix, 0, sizeof(matrix));
        while(cin >> symbol, symbol != "%")
        {
            aresta = stoi(symbol);
            aresta--;
            cin >> outra;
            outra--;
            matrix[aresta][outra] = 1;
            matrix[outra][aresta] = 1;

            hamilton(0, 0);
        }
    }
    return 0;
}

