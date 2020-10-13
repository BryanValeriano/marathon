#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'
#define int ll

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 2e5+5;
const int N = 11;

int k;
int v[T];
unordered_map<int,int> rest[N];

void insert(ll x) {
    for(int i = 1; i < N; i++) {
        x = (x*10ll)%k;
        rest[i][x]++;
    }
}

ll ele(ll x, ll e) {
    ll ans = 1;
    while(e) {
        if(e&1) ans = (x*ans)%k;
        x = (x*x)%k;
        e >>= 1;
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> v[i];
        insert(v[i]);
    }

    ll ans = 0;

    for(int i = 0; i < n; i++) {
        int need = (k-(v[i]%k))%k;
        int ok = (int)log10(v[i])+1;
        if(rest[ok].count(need))
            ans += (ll)rest[ok][need];
        if(((ll)v[i]*ele(10,ok))%k==need) ans--;
    }

    cout << ans << endl;
    return 0;
}

