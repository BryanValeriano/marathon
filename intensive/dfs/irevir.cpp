#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
int N, M;
const int MAX = 1e5 + 5;
vector<int>adj[MAX];
int visitados[MAX];

void dfs(int atual)
{
    visitados[atual] = 1;
    
    for(int i = 0; i < adj[atual].size(); i++)
        if(visitados[adj[atual][i]] == 0)
            dfs(adj[atual][i]);
}
 
int main(){
    ios_base::sync_with_stdio(false);
    int aux1, aux2, aux3, sinal;

    while(cin >> N >> M, N)
    { 
        for(int i = 0; i < M; i++)
        {
            cin >> aux1 >> aux2 >> aux3;
            adj[aux1].pb(aux2);
            if(aux3 == 2) adj[aux2].pb(aux1);
        }

        sinal = 0;
        for(int i = 1; i <= N; i++)
        {
            memset(visitados, 0, sizeof visitados);
            dfs(i);
        
            for(int j = 1; j <= N; j++)
            {
                if(!visitados[j])
                {
                    cout << 0 << endl;
                    sinal = 1;
                    break;
                }
            }

            if(sinal == 1) break;
        }

        if(sinal == 0) cout << 1 << endl;
        for(int i = 0; i <= N; i++) adj[i].clear();
    } 
    
    
    return 0;
}

