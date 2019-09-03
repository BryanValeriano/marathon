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
const int T = 1e5 + 10;
int v[T];

int main() {
    ios::sync_with_stdio(false);
    ll n, k; cin >> n >> k;
    ll aux;
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    for(ll i = 0; i < n; i++) {
        cin >> aux;
        pq.push(aux);
    }
    ll acum = 0;
    ll cont = 0;
    while(!pq.empty() and cont < k) {
        ll x = pq.top();
        pq.pop();
        if(x - acum == 0) continue;
        cout << x - acum << endl;
        acum += (x - acum);
        cont++;
    }
    while(cont < k) {
        cout << 0 << endl;
        cont++;
    }
    return 0;
}

