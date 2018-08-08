#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int row[n];
    for(int i = 0; i < n; i++)
        cin >> row[i];

    ll esq = 0; ll dir = 0; int ini = 0; int fim = n-1;
    ll resp = 0;
    while(ini <= fim) {
        if(esq < dir) esq += row[ini++];
        else dir += row[fim--];
        if(dir == esq) resp = dir;
    }
    cout << resp << endl;
        
    return 0;
}

