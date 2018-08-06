#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);
    int k, n;
    map<int , pair<int,int> >seqs;
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        cin >> n;
        int v[n], soma = 0;
        for(int j = 0; j < n; j++)
        {   
            cin >> v[j];
            soma += v[j];
        }
        int soma_parcial;
        for(int j = 0; j < n; j++)
        {
            soma_parcial = soma - v[j];

            if(seqs.find(soma_parcial) == seqs.end())
                seqs[soma_parcial] = mk(i+1, j+1);

            else if(seqs[soma_parcial].first != i+1)
            {
                cout << "YES" << endl;
                cout << seqs[soma_parcial].first << " " << seqs[soma_parcial].second << endl;
                cout << i+1<< " " << j+1 << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;

    return 0;
}

