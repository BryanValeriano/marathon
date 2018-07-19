#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pop pop_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;

int adl[20];
int maxx, minutes, tracks;
vector<int>vecmax;

vector<int> calc(int node, int cont, vector<int>ant)
{
    vector<int>musicas = musicas;
    musicas = ant;
    if(cont == minutes)
    {
        return musicas;
    }

    if(cont > maxx && cont < minutes)
    {
        maxx = cont;
        vecmax = ant;
    }
    for(int i = 0; i < tracks; i++)
    {
        if((cont + adl[i]) <= minutes)
        {
            cont += adl[i];
            musicas.pb(adl[i]);
            calc(i, cont, musicas);
            cont -= adl[i];
        }else{cont-=adl[i];}
        
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    
    cin >> minutes;

    while(minutes != EOF)
    {
        cin >> tracks;
        maxx = 0;
        memset(adl, 0, sizeof(adl));
        vecmax.clear();
        for(int i = 0; i < tracks; i++)
        {
            cin >> adl[i];
        }

        vector<int> ant;
        ant = calc(0, 0, ant);
        for(int i = 0; i < vecmax.size(); i++)
            cout << vecmax[i] << " ";
        cout << "sum:" <<  maxx << endl;

        cin >> minutes;
    }   
    
    return 0;
}

