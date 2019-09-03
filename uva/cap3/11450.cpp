#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
int N, M, C, K, aux, resposta, samuca;
vector<set<int> > roupas;
int dp[201][20];

int backtrack(int linha, int mleft)
{
    if(mleft < 0) return INT_MIN;

    if(linha == samuca) 
    {
        //cout << "ATENCAO!!" << " M: " << M << " mleft: " << mleft << endl; 
        return M - mleft;
    }

    if(dp[mleft][linha] != -1)
        return dp[mleft][linha];

    int maxval = INT_MIN;
    for(set<int>::iterator it = roupas[linha].begin(); it != roupas[linha].end(); ++it)
    {
        //cout << "Linha: " << linha << " iterator: " << *it;
        //cout << " Mleft: " << mleft << " M: " << M << endl;
        maxval = max(maxval, backtrack(linha + 1, mleft - *it));
    }
    return dp[mleft][linha] = maxval;
}

 
int main(){
    ios_base::sync_with_stdio(false);
    set<int> tmp;
    cin >> N;
    while(N--)
    {
        cin >> M >> C;
        samuca = C;
        while(C--)
        {
            cin >> K;
            tmp.clear();
            while(K--)
            {
                cin >> aux;
                tmp.insert(aux);
            }
            roupas.pb(tmp);
        }
        memset(dp, -1, sizeof dp);
        int resposta = backtrack(0, M);
        //cout << backtrack(0, M) << endl;
        if (resposta < 0) cout << "no solution" << endl;
        else              cout << resposta << endl;
        roupas.clear();
    }

	
    /*set<int>::iterator itSet;
    for (int i = 0; i < roupas.size(); i++) {
        for(itSet = roupas[i].begin(); itSet != roupas[i].end(); itSet++) {
                    cout << *itSet << ' ';
            }
            cout << endl;
    }*/
    
    return 0;
}

