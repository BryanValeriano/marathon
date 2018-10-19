#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int cont = 0;
    for(int i = 0; i < n; i++) {
        int aux = 0;
        int tmp;
        for(int j = 0; j < 3; j++) {
            cin >> tmp;
            aux += tmp;
        }
        if(aux >= 2) cont++;
    }
    cout << cont << endl;
    return 0;
}

