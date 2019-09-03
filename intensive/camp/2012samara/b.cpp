#include <bits/stdc++.h>

using namespace std;

int g[100];
int main (void) {
    g[1] = 0;
    for (int i = 2; i <= 50; i++) {
        set <int> vizinhanca;
        //pilha de tamanho i
        // tamanho j e i-j
        for (int j = 1; j < i; j++) {
            int k = i - j;
            vizinhanca.insert(g[j] ^ g[k]);
        }

        for (int x = 0; ; x++) {
            if (!vizinhanca.count(x)) {
                g[i] = x;
                break;
            }
        }
    }
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);
    int ans = 0;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int pilha; cin >> pilha;
        ans = ans ^ g[pilha];
    }
    
    printf("%s\n", ans ? "Constantine" : "Mike");
    return 0;
}
