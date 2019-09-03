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
    int cont = 0;
    int aux;
    while(n--) {
        cin >> aux;
        cont += aux;
    }
    if(cont > 0) cout << "HARD" << endl;
    else cout << "EASY" << endl;
    return 0;
}

