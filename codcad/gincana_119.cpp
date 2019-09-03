#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define TAM 1000

typedef long long ll;
int componentes[TAM];
int N;
vector<int> graph[TAM];

void dfs(int node)
{
    for(int i = 0; i < graph[node].size(); i++)
        if(componentes[graph[node][i]] == -1)
        {
            componentes[graph[node][i]] = 1;
            dfs(graph[node][i]);
        }
}
 
int main()
{
    int M, tmp1, tmp2;
    cin >> N >> M;
    for(int i = 1; i <= N; i++) componentes[i] = -1;

    for(int i = 0; i < M; i++)
    {
        cin >> tmp1 >> tmp2;
        graph[tmp1].pb(tmp2);
        graph[tmp2].pb(tmp1);
    }

    int cont = 0;

    for(int i = 1; i <= N; i++)
    {
        if(componentes[i] == -1)
            cont++;
            componentes[i] = 1;
            dfs(i);
    }
    cout << cont << endl;
    return 0;
}

