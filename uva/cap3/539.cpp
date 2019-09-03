#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;

int adl[26][26];
int maxx;

void calc(int node, int cont)
{
    if(cont > maxx) maxx = cont;

    for(int i = 0; i < 25; i++)
    {
        if(adl[node][i] == 1)
        {
            adl[node][i] = 0;
            adl[i][node] = 0;
            calc(i, cont + 1);
            adl[node][i] = 1;
            adl[i][node] = 1;

        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    
    int nodes ,edges, n, e;
    
    cin >> nodes >> edges;
    

    while(nodes && edges)
    {
        maxx = 0;
        memset(adl, 0, sizeof(adl));
        for(int i = 0; i < edges; i++)
        {
            cin >> n >> e;
            adl[n][e] = 1;
            adl[e][n] = 1;
        }

        for(int i = 0; i < 25; i++)
            calc(i, 0);

        cout << maxx << endl;

        cin >> nodes >> edges;
    }   
    
    return 0;
}

