#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;
int a,tanque,f,k,x1,x2;

bool aguenta(int volta, ll vezes) {
    ll gasto = 0;

    ll metade = vezes/2;

    if(!(vezes & 1)) gasto = (metade-1)*(2*x1) + metade*(2*x2);
    else gasto = metade*(2*x1) + metade*(2*x2);

    if(volta + metade >= k*2) gasto -= x2;
    return (tanque >= gasto);
}

ll chega() {
    ll metade = 0;
    ll gol = k * 2;
    
    if(tanque >= x1 + 2*x2) metade = 2;
    else metade = 1;

    while(metade < gol) {
        ll ini = 0;
        ll fim = 1e15;
        while(ini <= fim) {
            ll mid = (ini + fim) >> 1;
            if(aguenta(metade,mid)) ini = mid - 1;
            else fim = mid + 1;
        }

        metade += fim;
    }

    return metade;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> a >> tanque >> f >> k;
    x1 = f;
    x2 = a-f;
    cout << chega() << endl;

    return 0;
}

