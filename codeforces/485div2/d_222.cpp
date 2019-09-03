#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int TAM = 10e5 + 5;
vector<int>vizinhos[TAM];
vector<int>produtos[TAM];
int indice [105][TAM];
int n, m, k, s;

bfs(vector<int>prod, int* ind)
{
    queue<int>list;
    fill(ind + 1, ind + n + 1, -1);
    for(int x : prod)
    {
        list.push(x);
        ind[x] = 0;
    }
    while(!list.empt())
    {
        int atual = list.front(); list.pop();
        for(int elemento : vizinhos[atual])
        {
            if(ind[elemento] == -1)
            {
                ind[elemento] = ind[atual] + 1;
                list.push(elemento);
            }
        }
    }
}

int main()
{
    int x, y;
    cin >> n >> m >> k >> s;

    for(int i = 1; i <= k; i++)
    {
        cin >> x;
        produtos[x].pb(i);
    }
    for(int i = 0; i < m; i++)
    {
        cin >> x >> y;
        vizinhos[x].pb(y);
        vizinhos[y].pb(x);
    }

    for(int i = 1; i <= K; i++)
        bfs(produtos[i], indice[i]);

    for(int i = 1; i <= N; i++)
    {
        int resp[K];
        for(int j = 1; j <= K; j++)
            resp[j-1] = indice[j][i];
        sort(resp, resp + k);
        accumulate(resp, resp + s, 0);
    }

    cout << endl;
    
    return 0;
}

