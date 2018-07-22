#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int TAM = 1e4+3;
vector<pair<int, float> >cit[TAM];
float dev[TAM];
bool visitados[TAM];
float tanque;

int magicbk(int atual)
{
    visitados[atual] = true;
    float pegou = 0;
    int mindist = 0;
    for(int i = 0; i < cit[atual].size(); i++)
    {    
        int vizinho = cit[atual][i].fi;
        if(!visitados[vizinho])
        {
            mindist += magicbk(vizinho);
            float carga = dev[vizinho];
            float dist = cit[atual][i].se;
            mindist += (ceil(carga / tanque) * 2) * dist;
            pegou += carga;
            
        }
    }
    dev[atual] += pegou;
    return mindist;
}

int main()
{
    int n, aux, aux2;
    float aux3;
    cin >> n >> tanque;
    for(int i = 0; i < n; i++)
    {
        cin >> aux;
        dev[i + 1] = aux; 
    }
    for(int i = 0; i < n - 1; i++)
    {
        cin >> aux >> aux2 >> aux3; 
        cit[aux].pb(mk(aux2, aux3));
        cit[aux2].pb(mk(aux, aux3));
    }
    memset(visitados, 0, sizeof visitados);

    cout << magicbk(1) << endl;
    
    
    return 0;
}

