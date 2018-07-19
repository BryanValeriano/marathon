#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
const int TAM = 3e5 + 4;

typedef long long ll;
int n, x, y;
pair<int,int>prob;
vector<int>graph[TAM];
set< pair<int,int> >caminho;
int sinal;

void dfs(int fonte, int atual)
{

    pair<int,int>aux;
    pair<int,int>aux2;
    for(int i = 0; i < graph[atual].size(); i++)
    {
        aux = mk(atual, graph[atual][i]);
        aux2 = mk(fonte, graph[atual][i]);

        //if(fonte == aux.second);

        if(aux != prob && aux2 != prob && fonte != aux.second)
        { 
            caminho.insert(mk(fonte, aux.second));
            graph[atual].erase(graph[atual].begin() + i);
            dfs(fonte, aux.second);
            graph[atual].insert(graph[atual].begin() + i,  aux.second);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    int aux1, aux2;
    cin >> n >> x >> y;
    for(int i = 0; i < n - 1; i++)
    {
        cin >> aux1 >> aux2;
        graph[aux1].pb(aux2);
        graph[aux2].pb(aux1);
    }
    prob = mk(x,y);
    
    for(int i = 1; i <= n; i++)
    {
        sinal = 0;
        dfs(i, i);
    }

    //for(set< pair<int,int> >::iterator it = caminho.begin(); it != caminho.end(); ++it)
      // cout << "(" << it->first << ", " << it->second << ")" << endl;
    cout << caminho.size() << endl;
    
    return 0;
}

