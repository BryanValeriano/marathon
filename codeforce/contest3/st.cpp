#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    int subs = 0;
    int aux = N/2;
    int cont = 0;

    string str;

    string vet;

    cin >> vet;
   
    while(aux > 1)
    {
        str = vet.substr(0, aux);
        for(int j = aux; j < aux*2; j++)
        {
            if(str[j - aux] != vet[j])
            {
                aux--;
                break;
            }
            else if(j == (aux*2) - 1)
            {    
                vet = vet.erase(aux, aux);
                aux = 1;
                cont++;
                break;
            }
        }
    }

    cout << vet.size() + cont << endl;
    
    return 0;
}

