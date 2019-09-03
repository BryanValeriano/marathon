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

const int T = 1e5 + 2;
int pos[T];
int v[T];
int n,m,k;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    int x;
    
    for(int i = 1; i <= n; i++) {
        cin >> x;
        pos[x] = i;
        v[i] = x;
    }

    ll ans = 0;

    while(m--) {
        cin >> x;

        ans += (pos[x]/k) + (pos[x]%k? 1 : 0);

        if(pos[x] == 1) continue;
        int nxt = v[pos[x]-1];

        v[pos[x]] = nxt;
        v[pos[x]-1] = x;

        pos[x]--;
        pos[nxt]++;

    }
    
    cout << ans << endl;

    return 0;
}

