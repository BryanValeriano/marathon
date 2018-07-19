#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int TAM = 10e5 + 5;

int N, M, K, S;
vector<int>vizinhos[TAM];
vector<int>produtos[TAM];
int indice[105][TAM];

void bfs(vector<int>produto, int* ind)
{
    queue<int> list;
    fill(ind + 1, ind + N + 1, -1);
    for(int x : produto)
    {
        list.push(x);
        ind[x] = 0;
    }
    while(!list.empty())
    {
        int atual = list.front();
        list.pop();
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



int main(){
    ios_base::sync_with_stdio(false);
    int x, y;

    cin >> N >> M >> K >> S;
    for(int i = 1; i <= N; i++)
    {
        cin >> x;
        produtos[x].pb(i);
    }
    for(int i = 0; i < M; i++)
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
            resp[j - 1] = indice[j][i];
        sort(resp, resp + K);
        cout << accumulate(resp, resp + S, 0) << ' ';
    }
    cout << endl;


    return 0;
}

