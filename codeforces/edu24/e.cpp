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

const int T = 1e5 + 5;
const int N = 32;
int v[T][N];
vector<ii> primos;
int n,k;

void pre() {
    int tam = -1;
    for(ll i = 2; i*i <= k; i++) {
        if(k%i == 0) primos.eb(i,0), tam++;
        while(k%i == 0) k /= i, primos[tam].se++;
    }
    if(k != 1) primos.eb(k,1);
}

void pos(int x, int at) {
    for(int i = 0; i < primos.size(); i++) { 
        while(x % primos[i].fi == 0) {
            x /= primos[i].fi;
            v[at][i]++;
        }
    }
}

bool check(int ini, int fim) {
    bool ok = 1;
    
    for(int i = 0; i < primos.size(); i++) 
        ok &= ((v[fim][i] - (ini-1 >= 0? v[ini-1][i] : 0)) >= primos[i].se);

    return ok;
}

ll binSearch(int ini) {
    
    int l = ini;
    int r = n;
    int ans = n;

    while(l <= r) {
        int mid = (l+r) >> 1;
        if(check(ini,mid)) r = mid-1, ans = mid;
        else l = mid+1;
    }

    return n-ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    int x;
    cin >> n >> k;
    pre();
    
    for(int i = 0; i < n; i++) {
        cin >> x;
        pos(x,i);
    }

    for(int i = 0; i < primos.size(); i++)
        for(int j = 1; j < n; j++)
            v[j][i] += v[j-1][i];
    
    ll ans = 0;
    for(int i = 0; i < n; i++) ans += binSearch(i);
    cout << ans << endl;
    
    return 0;
}

