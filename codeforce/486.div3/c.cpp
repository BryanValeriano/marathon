#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int N = 2e5 + 5;
vector< pair<int,int> >seqs[N];

bool compare(const pair<int,int>&i, const pair<int,int>&j)
{
    return i.first < j.first;
}

int bisec(int dif, int pos)
{
    int inicio = 0;
    int fim = seqs[pos].size();
    int meio;
    while(inicio <= fim)
    {
        meio = (fim + inicio)/2;
        if(seqs[pos][meio].first == dif)
            return seqs[pos][meio].second;
        else if(seqs[pos][meio].first < dif) inicio = meio + 1;
        else fim = meio - 1;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    int k, tam, aux, x, y;
    cin >> k;
    int sums[k];
    memset(sums, 0, sizeof sums);
    for(int i = 0; i < k; i++)
    {
        cin >> tam;
        for(int j = 0; j < tam; j++)
        {
            cin >> aux;
            sums[i] += aux;
            seqs[i].pb(mk(aux, j));
        }
        sort(seqs[i].begin(), seqs[i].end(), compare);
    }


    for(int i = 0; i < k; i++)
    {
        for(int j = i + 1; j < k; j++)
        {
            int dif;
            for(int x = 0; x < seqs[i].size(); x++)
            {
                dif = sums[j] - (sums[i] - seqs[i][x].first);
                cout << "dif: " << dif << endl; 
                y = bisec(dif, j);
                if(y != -1)
                {
                    cout << "YES" << endl;
                    cout << j+1 << " " << y+1 << endl;
                    cout << i+1 << " " << seqs[i][x].second + 1 << endl;
                    return 0;
                }   
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}

