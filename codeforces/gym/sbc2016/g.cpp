#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int t = 505;
int ma [t][t];
int mb [t][t];
 
int main()
{
    int n, p; cin >> n >> p;
    int a, b;
    pair<int,int> preto[t];
    pair<int,int> branco[t];
    for(int i = 0; i < p; i++) {
        cin >> a >> b; 
        ma[a][b] = mb[a][b] = 2; 
        preto[i] = mk(a,b);
    }
    for(int i = 0; i < p; i++) {
        cin >> a >> b; 
        ma[a][b] = mb[a][b] = 1; 
        branco[i] = mk(a,b);
    }
    
    
    return 0;
}

