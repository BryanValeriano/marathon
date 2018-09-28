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
    int n; cin >> n;
    int aux;
    int cont1 = 0;
    int cont2 = 0;
    for(int i = 0; i < n; i++) {
        cin >> aux;
        if(aux == 5) cont1++;
        else cont2++;
    }
    while(cont1 % 9 != 0) cont1--;
    if(cont1 > 0 && cont2 > 0) { 
        for(int i = 0; i < cont1; i++) 
            cout << 5;
        for(int i = 0; i < cont2; i++)
            cout << 0;
    }
    else if(cont2 > 0) cout << 0;
    else cout << -1;
    cout << endl;

    return 0;
}

