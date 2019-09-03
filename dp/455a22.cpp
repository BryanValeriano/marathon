#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
const int INF = 0x3f3f3f3f;
int maxx = -INF;
int n; 
vector<int> tam;

int bk(int seila, int pecas)
{
    maxx = max(pecas, maxx);
    
    for(int i = 0; i < tam.size(); i++)
        if(seila + tam[i] <= n)
        {
            int tmp = tam[i];
            tam.erase(tam.begin() + i);
            return bk(seila + tam[i], pecas + 1);
            tam.insert(tam.begin() + i, tmp);
        }
}

int main()
{
    
    tam.reserve(3);
    cin >> n >> tam[0] >> tam[1] >> tam[2];    
    sort(tam.begin(), tam.end());
    bk(0,0);

    cout << maxx << endl;
    
    return 0;
}

