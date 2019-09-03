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
    ll resp = 0;
    int n, m; cin >> n >> m;
    int maxi = 0;
    int aux;
    cin >> maxi;
    for(int i = 1; i < m; i++) {
        cin >> aux;
        if(aux >= maxi) maxi = aux;
        else {
            resp += n;
            maxi = aux;
        }
    }
    if(maxi >= aux) resp += maxi;
    resp--;
    cout << (resp >= 0? resp : 0) << endl;
    
    return 0;
}

