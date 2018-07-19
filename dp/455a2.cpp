#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

int maxpont = 0;

void bk(map<int,int>tmp, int pontuacao, map<int,int>::iterator it)
{
    if(tmp.size() == 0) return;

    int pont = it->first;

    pontuacao += it->first * it->second;
    tmp.erase(pont);
    ++it;

    maxpont = max(pontuacao, maxpont);

    if(tmp.find(pont + 1) != tmp.end()) tmp.erase(pont + 1);
    if(tmp.find(pont - 1) != tmp.end()) tmp.erase(pont - 1);
    
    for(map<int,int>::iterator it2 = tmp.begin(); it2 != tmp.end(); ++it2)
        bk(tmp, pontuacao, it2);
}

int main()
{
    int a, x;
    cin >> a;
    map<int,int>ind;
    for(int i = 0; i < a; i++)
    {
        cin >> x;
        if(ind.find(x) != ind.end()) ind[x] += 1;
        else ind[x] = 1;
    }
    for(map<int,int>::iterator it = ind.begin(); it != ind.end(); ++it)
    {
        bk(ind, 0, it);
        //cout << "quase max: " << maxpont << endl;
    }

    cout << maxpont << endl;
    
    return 0;
}

