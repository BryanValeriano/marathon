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
const int T = 63000000 + 10;
ll maxi = 0;
int n, q;
priority_queue< ll, vector<ll> > pq;
ll ans[T];
vector<ll> v;

void print() {
    for(int i = 0; i < q; i++) {
        if(v[i] - 1 < T) cout << ans[v[i] - 1] << endl;
        else cout << 0 << endl;
    }
}

void solve() {
    int cont = 0;
    while(!pq.empty() and cont < maxi) {
            if(cont >= T) break;
        ans[cont] = pq.top();
        pq.pop();
        if(ans[cont] != 0 and ans[cont] / 2 > 0) pq.push(ans[cont]/2);
        cont++;
    }
}

void read() {
    ll aux;
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> aux;
        pq.push(aux);
    }
    for(int i = 0; i < q; i++) {
        cin >> aux;
        v.pb(aux);
        maxi = max(maxi, aux);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    read();
    solve();
    print();
    return 0;
}

