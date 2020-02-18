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

const int T = 1e3 + 5;
int qtd[T];
bool ok[T];
vector<int> promos[T];
int n,m;

bool check(int x) {
    int custo = 0;

    for(int i = 1; i <= x; i++)
        for(auto v : promos[i]) ok[v] = 1;

    for(int i = 1; i <= n; i++) {
        if(qtd[i]) {
            if(ok[i]) custo += qtd[i];
            else custo += qtd[i]*2;
        }
        ok[i] = 0;
    }


    return custo <= x;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> qtd[i];

    while(m--) {
        int a,b; cin >> a >> b;
        promos[a].pb(b);
    }

    int l = 0;
    int r = 1e3 + 5;
    int ans = r;

    while(l <= r) {
        int mid = (l+r) >> 1;
        if(check(mid)) ans = mid, r = mid-1;
        else l = mid+1;
    }

    cout << ans << endl; 
    
    return 0;
}

