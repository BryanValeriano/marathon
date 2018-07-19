#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;

int bisearch(int alvo,int vetor[], int tamanho)
{
    int inicio = 0;
    int fim = tamanho;
    int meio;
    while(fim - inicio > 1)
    {
        meio = (inicio + fim) >> 1;
        
        if(vetor[meio] > alvo) fim = meio;
        else inicio = meio;
    }
    return vetor[inicio];
}

int main(){
    ios_base::sync_with_stdio(false);

    int n, x, y, aux1, aux2, inicio, fim, melhor, tmp;
    melhor = INT_MAX;
    cin >> n >> x >> y;

    pair<int,int> contests[n];
    pair<int,int> hor[n];
    int V[x];
    int W[y];

    for(int i = 0; i < n; i++)
    {
        cin >> aux1 >> aux2;
        contests[i] = mk(aux1,aux2);
    }
    
    for(int i = 0; i < x; i++)
        cin >> V[i];
    
    for(int i = 0; i < y; i++)
        cin >> W[i];
    
    sort(V, V + x);
    sort(W, W + y);

    for(int i = 0; i < n; i++)
    {
        inicio = bisearch(contests[i].first, V, x);
        fim = bisearch(contests[i].second, W, y);

        cout << endl << "melhor para: " << contests[i].first << " " << contests[i].second << endl;
        cout << inicio << " " << fim;
        
        if(fim > inicio) tmp = fim - inicio;
        else tmp = (24 - inicio) + fim;
        if(tmp < melhor && inicio <= contests[i].first && fim >= contests[i].second) 
        {
            melhor = tmp;
            cout << " verdadeiro" << endl;
        }

        else cout << " falso" << endl;
        
        cout << "tmp: " << tmp << " melhor: " << melhor << endl;
    }
    cout << melhor + 1 << endl;
} 
