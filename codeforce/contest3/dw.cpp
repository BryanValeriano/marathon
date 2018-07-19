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
    int cont = N;
    vector <char> vet;
    char aux;

    for(int i = 0; i < N; i++)
    {
        cin >> aux;
        vet.pb(aux);
    }
    if(N > 1)
    {
        for(int i = 1; i < (int)vet.size(); i++)
        {
            if(vet[i-1] != vet[i])
            {
                cont--;
                vet.erase(vet.begin()+i);
            }
        }
    }

    cout << cont << endl;
    
    return 0;
}

