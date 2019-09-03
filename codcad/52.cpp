#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;


vector< pair<int,int> >indice;
int main()
{

    int N, M, aux, meio;
    cin >> N >> M;
    indice.pb(mk(0,0)); 
    for(int i = 0; i < N-1; i++)
    {
        cin >> aux;
        indice.pb(mk(aux, 0));
    }
    for(int i = 0; i < N; i++)
    {
        cin >> aux;
        indice[i].second = aux;
    }

    for(int i = 0; i < M; i++)
    {
        cin >> aux;
        int ini = 0;
        int fim = indice.size();
        while(fim - ini > 1)
        {
            meio = (fim + ini)/2;
            if(indice[meio].first == aux) break;
            else if(indice[meio].first > aux) fim = meio;
            else ini = meio;
        }
        if(aux < indice[meio].first && meio > 0) cout << indice[meio - 1].second << " ";
        else cout << indice[meio].second << " ";
    }
    
    return 0;
}

