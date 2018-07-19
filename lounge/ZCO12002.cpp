#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);

    int n, x, y, aux1, aux2, l, r, sinal, m;
    cin >> n >> x >> y;

    pair<int,int> contests[n];
    pair<int,int> hor[n];
    int V[x];
    int W[y];

    for(int i = 0; i < n; i++)
    {
        cin >> aux1 >> aux2;
        contests[i] = mk(aux1,aux2);
    }
    
    for(int i = 0; i < x; i++)
        cin >> V[i];
    
    for(int i = 0; i < y; i++)
        cin >> W[i];
    
    sort(V, V + x);
    sort(W, W + y);
    
    for(int i = 0; i < n; i++)
    {
        l = 0, r = x;
        sinal = 0;

        while(r - l > 1)
        {
            m = (l + r) / 2;

            if(V[m] == contests[i].first)
            {
                hor[i].first = V[m];
                sinal = 1;
                break;
            }
            else if(V[m] > contests[i].first) l = m;
            else r = m;
        }
        if(sinal != 1)  hor[i].first = V[r];
        cout << "l eh: " << l << endl;
        cout << "r eh: " << r << endl;
        
        sinal = 0;
        l = 0, r = y;
        while(r - l > 1)
        {
            m = (l + r) / 2;

            if(V[m] == contests[i].second)
            {
                hor[i].second = W[m];
                sinal = 1;
                break;
            }
            else if(W[m] > contests[i].second) l = m;
            else r = m;
        }
        if(sinal != 1)  hor[i].second = W[r];
    } 

    for(int i = 0; i < n; i++)
        cout << hor[i].first << ", " << hor[i].second << " ";

    cout << endl;



    return 0;
}

