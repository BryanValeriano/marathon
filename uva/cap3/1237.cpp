#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;

typedef struct company
{
    char nome[20];
    int low;
    int high;
}
company;

int main(){
    ios_base::sync_with_stdio(false);

    int TC, data, query, preco, target, sinal;
    string nome;
    cin >> TC;
    vector<company> search;
    company tmp;
    while(TC--)
    {
        cin >> data;
        search.clear();
        sinal = 0;
        for(int i = 0; i < data; i++)
        {
            cin >> tmp.nome >> tmp.low >> tmp.high;
            search.pb(tmp);
        }
        cin >> query;
        for(int i = 0; i < query; i++)
        {
            cin >> preco;
            for(int i = 0; i < data; i++)
                if(search[i].low <= preco && search[i].high >= preco)
                {
                    target = i;
                    sinal++;
                }
            if(sinal == 1) cout << search[target].nome << endl;
            else cout << "UNDETERMINED" << endl;
            sinal = 0;
        }
        if(TC) cout << endl;
    }
    
    return 0;
}

