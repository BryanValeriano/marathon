#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
const ll INF = -1e18;
const int T = 3e5 + 100;
const ll N = sqrt(T)+2;

vector<ll> v;
ll bucket[N + 5];
ll maxPre[N + 5];
int id[N + 5];
ll n, k;

ii query(int l, int r) {
    int primeiro = l/N;
    int segundo = r/N;

    ll best = INF;
    ll pos = l;
    ll qtd = 0;

    while(l/N == primeiro and l <= r) {
        qtd += v[l++];
        if(qtd >= best) {
            best = qtd;
            pos = l-1;
        }
    }

    while(l/N < segundo) {
        if(qtd + maxPre[l/N] >= best) {
            best = qtd + maxPre[l/N];
            pos = id[l/N];
        }
        qtd += bucket[l/N];
        l += N;
    }

    while(l <= r) {
        qtd += v[l++];
        if(qtd >= best) {
            best = qtd;
            pos = l-1;
        }
    }

    return mk(best,pos);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v.pb(x);
    }

    reverse(v.begin(), v.end());
    for(int i = 0; i < N+5; i++) maxPre[i] = INF;

    for(int i = 0; i < n; i++) {
        bucket[i/N] += v[i];
        if(bucket[i/N] >= maxPre[i/N]) {
            maxPre[i/N] = bucket[i/N];
            id[i/N] = i;
        }
    }

    ll ans = 0;
    int l = 0;
    int r = n-k;

    while(k) {
        if(k == 1) {
            for(int i = l; i < n; i++) ans += v[i];
            break;
        }

        ii ok = query(l,r);
        ans += ok.fi * k;

        l = ok.se+1; r++;
        k--;
    }

    cout << ans << endl;
    return 0;
}

