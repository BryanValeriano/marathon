#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
vector<int >lista[100005];
int pesos[100005];
int N, sinal = 0;

void backtrack()
{
    int base;

    for(int i = 0; i <= N; i++)
    {
        if(lista[i].size() != 0) base = pesos[lista[i][0]];
        else base = 1;
        for(int j = 0; j < lista[i].size(); j++)
            if(base != pesos[lista[i][j]]) sinal = 1;
    }
}


int weight(int node)
{
    if(lista[node].size() == 0) return 1;

    for(int i = 0; i < lista[node].size(); i++)
        pesos[node] += weight(lista[node][i]);

    return pesos[node];
}

int main(){
    ios_base::sync_with_stdio(false);
    int tmp1, tmp2;
    cin >> N;
    

    for(int i = 0; i < N; i++)
    {   
        cin >> tmp1 >> tmp2;
        lista[tmp2].pb(tmp1);
    }
   
    
    for(int i = 0; i <= N; i++) pesos[i] = 1;
    weight(0);
    //for(int i = 0; i <= N; i++) cout << i << " " <<pesos[i] << ", ";
    //cout << endl;
    backtrack();
    (sinal == 0)? cout << "bem" : cout << "mal";
    cout << endl;
    
    
    return 0;
}

