#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    char txt[n];
    cin >> txt;

    int inicio = 0;
    int fim = 0;

    int tamanho;

    tamanho = 0;
    int y = 0;
    int c = 0;
    int cont = 0;    
    int f = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(txt[i] == txt[j])
            {
                for(int k = i, l = j; k <= j && l >= i; k++, l--)
                {
                    if(txt[k] == txt[l])
                    {
                        cont++;
                    }
                }
                if(cont == (j+1) - i)
                {
                    if(cont > tamanho)
                    {
                        tamanho = (cont);
                        inicio = i;
                        fim = j;
                    } 
                }
                cont = 0;
                f = 0;
            }
        }
    }
    
    cout << tamanho << endl;
     
    for(int i = inicio; i <= fim; i++)
    {
        cout << txt[i];
    }
    cout << endl;
    return 0;   
}            
