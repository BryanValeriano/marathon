#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;

ll board[14];
ll maxx;


ll score(ll tmp[14])
{
    //cout << "Teste: " << endl;

    ll total = 0;
    for(int i = 0; i < 14; i++)
    {
        //cout << tmp[i] << " ";
        if(tmp[i] % 2 == 0 && tmp[i] != 0 && tmp[i] != 1)
            total += tmp[i]; 
    }

    //cout << endl;

    return total;
}

void coloca(int start, int tamanho, ll tmp[14])
{
    int cont; 
    for(int i = start; i < start + tamanho; i++)
    {
        cont = i % 14;
        tmp[cont] += 1;
    }
}           

int place()
{   
    ll qtd, placar;
    ll resto;
    ll tmp[14];

    for(int i = 0; i < 14; i++)
    {
        if(board[i] != 0)
        {
            for(int j = 0; j < 14; j++)
                tmp[j] = board[j];

            if(board[i] < 14)
            {
                qtd = tmp[i];
                tmp[i] = 0;
                coloca(i+1, qtd, tmp);
                placar = score(tmp);
            }
            else
            {
                qtd = board[i]/14;
                resto = board[i] - (board[i]/14)*14;
                tmp[i] = 0;
                for(int j = 0; j < 14; j++)
                    tmp[j] += qtd;
                coloca(i+1, resto, tmp);
                placar = score(tmp);
            }

            if(placar > maxx) maxx = placar;
        }
    }
}
                




int main(){
    ios_base::sync_with_stdio(false);
    for(int i = 0; i < 14; i++)
        cin >> board[i];

    place();

    cout << maxx << endl;
    
    
    return 0;
}

