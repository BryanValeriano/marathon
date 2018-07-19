#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;

bk(int fonte, int atual, int qtd, int dist)
{
    for(int i = 1; i < graph[atual].size(); i++)
    {
        if(graph[fonte][0].second != graph[atual][i])
        {
            coins += dist;
            qtd--;
            if(qtd == 0) 
            {
                sinal = 1;
                break;
            }
        }
    }
}


     
 
int main(){
    ios_base::sync_with_stdio(false);

    int N,M,K,S;
    int aux1, aux2;
    cin >> N >> M >> K >> S;
    vector< pair<int,int> >graph[N + 1];
    for(int i = 1; i <= N; i++)
    {
        cin >> aux1;
        graph[i].pb(mk(i, aux1));
    }

    for(int i = 0; i < M; i++)
    {
        cin >> aux1 >> aux2;
        graph[aux1].pb(graph[aux2][0]);
        graph[aux2].pb(graph[aux1][0]);
    }

    //for(int i = 1; i <= N; i++)
        //graph[i].erase(graph[i].begin());
    int cont = 0;
    int coins = 0;
    int sinal = 0;
    for(int i = 1; i <= N; i++)
    {
        cont = 0;
        sinal = 0;
        //menor caminho p/ s-1 vertices, tal que [vertice].second != [i].second
        for(int j = 1; j < graph[i].size(); j++)
        {
            if(graph[i][0].second != graph[i][j].second)
            {
                cont++;
                coins += 1;
                if(cont == s)
                {
                    sinal = 1;
                    cout << coins << " ";
                    break;
                }
            }
            if(sinal == 0)
            {
                for(int j = 1; j < graph[i].size(); j++)
                {
                    bk(i, graph[i][j], s-cont, 2);
    }

    
    return 0;
}

