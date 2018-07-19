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
vector<int>ant;

void calc(int node, int cont)
{
    if(cont > maxx)
    { 
        maxx = cont;
        vecmax = ant;
    }

    for(int i = node; i < tracks; i++)
        if((cont + adl[i]) <= minutes)
        {
            cont += adl[i];
            ant.pb(adl[i]);
            
            calc(i + 1, cont);
            
            ant.pop();
            cont -= adl[i];
        }
}

int main(){
    ios_base::sync_with_stdio(false);
    
    while(cin >> minutes)
    {
        cin >> tracks;
        maxx = 0;
        
        memset(adl, 0, sizeof(adl));
        vecmax.clear();
        ant.clear();
        
        for(int i = 0; i < tracks; i++)
        {
            cin >> adl[i];
        }

        calc(0, 0);

        for(int i = 0; i < vecmax.size(); i++)
            cout << vecmax[i] << " ";
        cout << "sum:" <<  maxx << endl;
    }   
    return 0;
}

