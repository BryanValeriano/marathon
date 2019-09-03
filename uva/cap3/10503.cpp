#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
int N, M, tail, para = 0;
vector< pair<int,int> > pecas;
vector< pair<int,int> > track;
pair<int,int>ponta1;
pair<int,int>ponta2;


void backtrack()
{
    int lastail;
    if(para == 1) return;

    pair<int,int>last;

    if(track.size() == N)
        if(tail == ponta2.first)
        {
            para = 1;
            return;
        }

    for(int i = 0; i < pecas.size(); i++)
    {
        if(pecas[i].first == tail && track.size() <= N)
        {
            lastail = tail;
            track.pb(pecas[i]);
            tail = pecas[i].second;
            last = pecas[i];
            pecas.erase(pecas.begin() + i);
            backtrack();
            pecas.insert(pecas.begin() + i, last);
            track.pop_back();
            tail = lastail;
        }

        else if(pecas[i].second == tail && track.size() <= N)
        {
            lastail = tail;
            track.pb(pecas[i]);
            tail = pecas[i].first;
            last = pecas[i];
            pecas.erase(pecas.begin() + i);
            backtrack();
            pecas.insert(pecas.begin() + i, last);
            track.pop_back();
            tail = lastail;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    int aux1, aux2;
    pair<int,int>aux;
    cin >> N;

    while(N != 0)
    {
        cin >> M;
        cin >> aux1 >> aux2;
        ponta1 = mk(aux1, aux2);
        cin >> aux1 >> aux2;
        ponta2 = mk(aux1, aux2);

        for(int i = 0; i < M; i++)
        {
            cin >> aux1 >> aux2;
            aux = mk(aux1, aux2);
            pecas.pb(aux);
        }

        tail = ponta1.second;
        para = 0;
        backtrack();
        cout << (para ? "YES" : "NO") << endl;
        track.clear();
        pecas.clear();
        cin >> N;
    }
    
    return 0;
}

