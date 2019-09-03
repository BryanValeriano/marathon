#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;

int bin(int ini, int fim, ll arrows, ll acumulate[]) {
    int meio = (ini + fim)/2;
    while(fim >= ini) {
        meio = (ini + fim)/2;
        if(acumulate[meio] == arrows) {
            return meio;
        }
        else if(acumulate[meio] > arrows) fim = meio - 1;
        else ini = meio + 1;
    }
    return fim;
}
    

int main() {
    int n, q;
    cin >> n >> q;
    ll acumulate[n];
    cin >> acumulate[1];
    for(int i = 2; i <= n; i++) {
        cin >> acumulate[i];
        acumulate[i] += acumulate[i-1];
    }

    ll arrows;
    ll resto = 0;
    for(int i = 0; i < q; i++) {
        cin >> arrows;
        arrows += resto;
        int ini = 1;
        int fim = n;
        int resp = bin(ini, fim, arrows, acumulate); 
        if(resp == n) {
            //cout << "resp1: " << resp << "arrows: " << arrows << endl;
            cout << n << endl;
            resto = 0;
        }
        else {
            //cout << "resp2: " << resp  << " arrows: " << arrows << endl;
            cout << ((n - 1) - resp) + 1 << endl;
            resto = arrows;
        }
    }

    return 0;
}

