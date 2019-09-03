#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

const int T = (1e5 + 10) * 30;
int trie[T][2];
int qtd[T];
int cont;

void update(int x, int k) {
    int at = 0;
    for(int i = 30; i >= 0; i--) {
        qtd[at] += k;
        bool bit = (x & (1 << i));
        if(!trie[at][bit]) trie[at][bit] = ++cont;
        at = trie[at][bit];
    }
    qtd[at] += k;
}

int query(int p, int l) {
    int at = 0;
    int ans = 0;

    for(int i = 30; i >= 0; i--) {
        bool pp = (p & (1 << i));
        bool ll = (l & (1 << i));
        bool bit = (pp^ll);

        if(ll && trie[at][pp]) ans += qtd[trie[at][pp]];
        
        if(!trie[at][bit]) return ans;
        at = trie[at][bit];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int q, op, a, b; cin >> q;

    while(q--) {
        cin >> op >> a;
        if(op == 1) update(a,1);
        else if(op == 2) update(a,-1);
        else {
            cin >> b;
            cout << query(a,b) << endl;
        }
    }

    return 0;
}

