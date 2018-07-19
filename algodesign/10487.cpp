#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
vector<int> numeros;

int bruteforce(int alvo)
{
    int melhordist = INT_MAX;
    int melhor = numeros[0] + numeros[1];
    int tentativa;

    for(int i = 0; i < numeros.size(); i++)
        for(int j = i + 1; j < numeros.size(); j++)
        {
            tentativa = abs((numeros[i] + numeros[j]) - alvo);
            if(tentativa < melhordist)
            {
                melhordist = tentativa;
                melhor = numeros[i] + numeros[j];
            }
        }
    return melhor;
}

int main(){
    ios_base::sync_with_stdio(false);
    int TC, input, query, melhor, alvo, tmp;
    int linecounter = 0;

    cin >> TC;
    while(TC)
    {
        for(int i = 0; i < TC; i++)
        {
            cin >> tmp;
            numeros.pb(tmp);
        }
        cin >> query;
        cout << "Case " << ++linecounter << ":" << endl;
        while(query--)
        {
            cin >> alvo;
            melhor = bruteforce(alvo);
            cout << "Closest sum to "<< alvo << " is " << melhor << "." << endl;
        }
        numeros.clear();
        cin >> TC;
    }
    return 0;
}

