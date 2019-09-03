#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;

int countvotos(int matrix[], int tamanho, int inicio, int max)
{
    int j = inicio;
    int counter = 0;
    for(int i = 0; i < tamanho; i++)
    {
        if(matrix[i*tamanho+j] == 1)
        {
            counter += 1;
        }
    }
    if (counter > max) max = counter;
    if(j < tamanho) return countvotos(matrix, tamanho, inicio + 1, max);
    
    return max;
}

int main(){
    ios_base::sync_with_stdio(false);
    
    int tamanho = 1;
    int max;

    while(tamanho != 0)
    {

        cin >> tamanho;
        if(tamanho == 0) return 0;
        max = 0;

        int matrix[tamanho*tamanho];
        for(int i = 0; i < tamanho; i++)
        {
            for(int j = 0; j < tamanho; j++)
            {
                cin >> matrix[i*tamanho+j];
            }
        }

        max = countvotos(matrix, tamanho, 0, 0);

        cout << max << endl;
    }
    
    return 0;
}
