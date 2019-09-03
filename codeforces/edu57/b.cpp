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
const int T = 2e5 + 10;
const int MOD = 998244353;
ll n, ini, fim;
string s;

void contfim() {
    int cont = 0;
    for(int i = n-1; i > 0; i--) { 
        if(s[i] == s[n-1]) cont++;
        else break;
    }
    fim = cont;
}

void contini() {
    int cont = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == s[0]) cont++;
        else break;
    }
    ini = cont;
}

void acha() {
    cin >> n >> s;
    contfim();
    contini();
    if(s[0] != s[n-1]) cout << (ini + fim + 1) % MOD << endl;
    else cout << ((ini + fim + 1 % MOD) + (ini * fim) % MOD) % MOD << endl;
}

int main() {
    ios::sync_with_stdio(false);
    acha();

    return 0;
}

