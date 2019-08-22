#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 3e5 + 3;
const int N = 1e6 + 3;
//bitset<N> crivo;
//vector<int> primes;
int dv[N];
int v[T];
int cache[N];
ll seg[4*T];
set<int> lista;
int a, b, val;

void build(int node, int i, int j) {
    if(i == j) seg[node] = v[i];
    else {
        int mid = (i+j) >> 1;
        build(2*node,i,mid);
        build(2*node+1,mid+1,j);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
}

void update(int node, int i, int j) {
    if(i > b or j < a) return;
    if(i >= a and j <= b) seg[node] = v[i];
    else {
        int mid = (i+j) >> 1;
        update(2*node,i,mid);
        update(2*node+1,mid+1,j);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
}

ll query(int node, int i, int j) {
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) return seg[node];
    int mid = (i+j) >> 1;
    return query(2*node,i,mid) + query(2*node+1,mid+1,j);
}

//void init() {
//    for(int i = 2; i < N; i++) {
//        if(!crivo[i]) {
//            primes.pb(i);
//            for(int j = i+i; j < N; j += i) crivo[j] = 1;
//        }
//    }
//}
//
//int numDiv(ll x) {
//    int i = 1;
//    int ori = x;
//    ll pf = primes[0], ans = 1;
//
//    if(x == 1) return 1;
//    if(crivo[x] == 0) return 2;
//    if(cache[x]) return cache[x];
//
//    while(i < primes.size() and pf*pf <= x) {
//        ll power = 0;
//        while(x%pf == 0) x /= pf, power++;
//        ans *= (power+1);
//        pf = primes[i++];
//    }
//
//    if(x != 1) ans *= 2;
//    cache[ori] = ans;
//    return ans;
//}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //init();
    int n,q;
    cin >> n >> q;

    for(int i = 1; i < N; i++)
        for(int j = i; j < N; j += i)
            dv[j]++;

    for(int i = 1; i <= n; i++) cin >> v[i], lista.insert(i);
    build(1,1,n);

    int op;
    vector<int> del;

    while(q--) {
        cin >> op >> a >> b;
        if(op == 2) cout << query(1,1,n) << endl;

        else {
            int aa = a;
            int bb = b;

            if(lista.size() == 0) continue;
            auto at = lista.lower_bound(aa);
            if(at == lista.end()) continue;

            while(at != lista.end() and *at <= bb) {
                int novo = dv[v[*at]];
                if(novo == v[*at]) { del.pb(*at); at++; continue; }
                v[*at] = novo;
                a = b = *at;
                update(1,1,n);

                if(novo <= 2) del.pb(*at);
                at++;
            }

            for(int i = 0; i < del.size(); i++) lista.erase(del[i]);
            del.clear();
        }
    }


    return 0;
}

