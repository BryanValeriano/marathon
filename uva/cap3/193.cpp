#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
vector<int>matrix[102];
int maxx = 0;
map<int,int>proibidos;
set<int>track;
set<int>best;

int n, k;

int backtrack(int x)
{
    if(track.size() > maxx)
    {
        maxx = track.size();
        best = track;
        /*set<int> ::iterator it;
        for(it = track.begin(); it != track.end(); it++)
            cout << *it << " ";
        cout << endl;*/
    }


    for(int i = x; i < 102; i++)
    {
        if(proibidos.count(i) == 0 && track.count(i) == 0 && matrix[i].size() != 0)
        {
            track.insert(i);
            for(int j = 0; j < matrix[i].size(); j++)
            {
                proibidos[matrix[i][j]]++;
            }
            backtrack(i + 1);

            track.erase(i);
            for(int j = 0; j < matrix[i].size(); j++)
            {
                proibidos[matrix[i][j]]--;
                if(proibidos[matrix[i][j]] <= 0) proibidos.erase(matrix[i][j]);
            }
        }
    }
}
        
int main(){
    ios_base::sync_with_stdio(false);
    int M, aux1, aux2;
    cin >> M;

    while(M--)
    {
        cin >> n >> k;
        
        for(int i = 0; i < k; i++)
        {
            cin >> aux1 >> aux2;
            matrix[aux1].pb(aux2);
            matrix[aux2].pb(aux1);
        }
        
        backtrack(1);
        
        for(int i = 1; i <= n; i++)
        {
            if(matrix[i].size() == 0)
            {
                maxx += 1;
                best.insert(i);
            }
        }
        cout << maxx << endl;
        
        set<int> ::iterator it;
        set<int> ::iterator aux;
        for(it = best.begin(); it != best.end(); it++)
        {
            cout << *it;
            aux = it;
            aux++;
            if(aux != best.end()) cout << " ";
        }
        
        cout << endl;
        
        for(int i = 0; i < 102; i++)
        {
            matrix[i].clear();
        }
        track.clear();
        proibidos.clear();
        best.clear();
        maxx = 0;
    }
    
    
    return 0;
}

