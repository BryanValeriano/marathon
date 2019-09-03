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

const int T = 1e6 + 10;
int bit[T];
int ve[T];
int track[T];
ll f[T];
vector<int> v;
map<int,int> id;

void update(int x, int val) {
    for(int i = x; i < T; i += i&-i) bit[i] = max(val, bit[i]);
}

int query(int x) {
    int ans = 0;
    for(int i = x; i > 0; i -= i&-i) ans = max(ans, bit[i]);
    return ans;
}

void pre() {
    int cont = 1;
    for(int i = 3; i < T; i++) {
        f[i] = f[i-1] + cont;
        cont++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    pre();
    f[2] = 1;
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> ve[i];
        v.pb(ve[i]);
    }
    sort(ve, ve+n);
    for(int i = 0; i < n; i++) id[ve[i]] = i+2;

    reverse(v.begin(), v.end()); 

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int ant = query(id[v[i]]-1);
        update(id[v[i]], ant+1);
        track[ant+1]++;  
        if(ant+1 == 3) ans++;
        else if(ant+1 > 3) {
            ll qtd = f[ant+1];
            ans += qtd * track[ant];
        }
    }
    
    cout << ans << endl;

    return 0;
}

