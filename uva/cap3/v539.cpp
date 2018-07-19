#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;

int maxx;
vector<int>adl[30];
set< pair<int, int> > visit;

void calc(int node, int cont)
{
    if(cont > maxx) maxx = cont;

    for(int i = 0; i < adl[node].size(); i++)
    {
        pair<int,int> p(node, adl[node][i]);
        pair<int,int> p2(adl[node][i], node);
        set< pair <int, int> > ::iterator it = visit.find(p);
        set< pair <int, int> > ::iterator it2 = visit.find(p2);
        if(it == visit.end() && it2 == visit.end())
        {
            visit.insert(p);
            calc(adl[node][i], cont + 1);
            visit.erase(p);
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
            adl[n].pb(e);
            adl[e].pb(n);
        }
        for(int i = 0; i <= 25; i++)
            calc(i, 0);

        cout << maxx << endl;

        cin >> nodes >> edges;
    }   
    return 0;
}

