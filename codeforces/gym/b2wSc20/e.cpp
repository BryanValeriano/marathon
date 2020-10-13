#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e5+5;

priority_queue<ll,vector<ll>,greater<ll>> bag[T];
priority_queue<ll,vector<ll>> bag2[T];
map<string,int> aux;
int cont;

int id(string s) {
    if(aux.count(s)) return aux[s];
    aux[s] = ++cont;
    return cont;
}

ll tent(int x) {
    ll compra = (bag[x].empty()? INF : bag[x].top());
    ll venda = (bag2[x].empty()? -INF : bag2[x].top());
    if(venda-compra > 0) {
        bag[x].pop();
        bag2[x].pop();
        return venda-compra;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    ll ans = 0;

    while(n--) {
        string s,t;
        ll v;
        cin >> s >> t >> v;
        int x = id(t);
        if(s[0] == 'C') bag[x].push(v);
        else bag2[x].push(v);
        ans += tent(x);
    }

    cout << ans << endl;
    return 0;
}

