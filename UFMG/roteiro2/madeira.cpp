#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);

    int n;
    string tmp;
    cin >> n;
    getline(cin, tmp);
    int sum;
    string nome;
    map<string, float> especie;

    for(int i = 0; i < n; i++)
    {
        sum = 0;
        while(getline(cin, nome))
        {
            if(especie[nome]) especie[nome] = especie[nome] + 1;
            else
            {
                especie.insert(mk(nome, 1));
            }
            sum++;
        }
        for(map<string, float>::iterator it = especie.begin(); it != especie.end(); ++it)
        {
            it->second = it->second/sum;
            cout << it->first << " " << setw(5) << it->second << endl;
        }
        especie.clear();
        cout << endl;
    }

    
    return 0;
}

