#include <bits/stdc++.h>
using namespace std;

const int T = (1<<15) - 1;
int probs[T];
int n, ans, gol;

void solve(int lin, int ld, int rd) {
    if(lin == gol) { ans++; return; }
    int pos = gol & (~(lin | ld | rd | probs[__builtin_popcount(lin)]));
    while(pos) {
        int p = pos & -pos;
        pos -= p;
        solve(lin | p, (ld | p) << 1, (rd | p) >> 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    cin.tie(NULL);
    cout.tie(NULL);
    int cont = 0;
    while(n) {
        char aux;
        ans = 0;
        gol = (1<<n) - 1;
        for(int i = 0; i < n; i++) {
            probs[i] = 0;
            for(int j = 0; j < n; j++) {
                cin >> aux;
                if(aux == '*') probs[i] |= (1<<j);
            }
        }
        solve(0,0,0);
        cout << "Case " << ++cont << ": " << ans << endl;
        cin >> n;
    }
    return 0;
}

