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
const int T = 1e5;
bool a[T+5];
vector<int>crivo;
ll n;

void cri() {
    for(ll i = 2; i <= T; i++) {
        if(a[i] == false) {
            crivo.pb(i);
            for(ll j = i+i; j <= T; j += i)
                a[j] = true;
        }
    }
}

int prim(ll x) {
    for(auto i : crivo)
        if(x%i == 0) return i;
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cri();
    ll n; cin >> n;
    int div = prim(n);
    if(div == -1) { cout << 1 << endl; return 0; }
    int cont = 0;
    if(div != 2) { n -= div; cont++; }
    cout << (n/2) + cont << endl;
    return 0;
}

