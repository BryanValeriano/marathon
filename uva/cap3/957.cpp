#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int TAM = 1e7 + 3;
int qtd[TAM];
 
int main()
{
    int intervalo;
    while(cin >> intervalo)
    {
        memset(qtd, 0, sizeof qtd);
        int papas;
        cin >> papas;
        int aux, FIM, fim, INI, ini, test, semnada;
        int maxx = 0;
        for(int i = 0; i < papas; i++)
        {
            cin >> aux;
            qtd[aux] += 1;
        }
        for(int i = 1; i < TAM; i++)
        {
            int test = qtd[i];
            qtd[i] += qtd[i - 1];
            if(qtd[i] == test)
                semnada++;
            else semnada = 0;

            if(i >= intervalo)
            {
                fim = qtd[i];
                ini = qtd[i- intervalo];
                if(maxx < fim - ini)
                {
                    maxx = fim - ini;
                    int tmp = qtd[i - semnada];
                    FIM = i - semnada;
                    if(tmp == qtd[FIM - 1])
                    {
                        FIM--;
                        while(tmp == qtd[FIM]) FIM--;
                        FIM++;
                    }
                    tmp = qtd[i - (intervalo - 1)];
                    INI = i - (intervalo - 1);
                    if(tmp == qtd[INI - 1])
                    {
                        INI++;
                        while(tmp == qtd[INI])INI++;
                    }
                } 
            }
        }
        cout << maxx << " " << INI << " " << FIM << endl; 
    }
    return 0;
}

