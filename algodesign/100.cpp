#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
vector<int> caminho;
map<int,int>dp;

void marca(int tamanho)
{
    for(int i= 0; i < caminho.size(); i++)
    {
        if(!dp.count(caminho[i]))
            dp.insert(mk(caminho[i], tamanho - i));
       // else break;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int k, n, m, cont1, maxx, inf, sup;
    
    while(cin >> n)
    {
        cin >> m;
        cout << n << " " << m << " ";
        maxx = 1;
        inf = min(n,m);
        sup = max(n,m);


        for(int i = inf; i <= sup; i++)
        {
            k = i;
            cont1 = 1;
            caminho.pb(i);
            while(k != 1) 
            {
                if(dp.count(k))
                {
                    cont1 += dp[k] - 1;
                    break;
                }
                if(k % 2 == 0 && k != 1)
                {
                    k = k/2;
                    cont1++;
                    caminho.pb(k);
                } 
                else if(k != 1) {
                    k = 3*k + 1;
                    cont1++;
                    caminho.pb(k);
                }        
            }
            if(cont1 > maxx) maxx = cont1;
            marca(maxx);
            caminho.clear();
        }
        cout << maxx << endl;
    }
    
    return 0;
}

