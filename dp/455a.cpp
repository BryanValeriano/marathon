#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
int maxpont = 0;

void bk(map<int,int>tmp, int pontuacao, map<int,int>::iterator it)
{
    if(tmp.size() == 0) return;

    int pont = it->first;
    //cout << "iterator: (" << it->first << "," << it->second << ")" << endl;


    if(tmp[pont] == 1) 
    {
        //cout << "delete: " << pont << endl;
        tmp.erase(pont);
        ++it;
    }
    else tmp[pont] -= 1;

    maxpont = max(pontuacao + pont, maxpont);

    if(tmp.find(pont + 1) != tmp.end()) tmp.erase(pont + 1);
    if(tmp.find(pont - 1) != tmp.end()) tmp.erase(pont - 1);
    
    for(map<int,int>::iterator it2 = tmp.begin(); it2 != tmp.end(); ++it2)
        bk(tmp, pontuacao + pont, it2);
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

