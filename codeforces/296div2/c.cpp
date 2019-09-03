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

const int T = 1e5 + 3;

ll v[T][2];
ll l[T], r[T], d[T];

int n,m,k;

void update(int pos, ll sum, int op) {
    for(; pos < T; pos += pos&-pos) v[pos][op] += sum;
}

ll query(int pos, int op) {
    ll ans = 0;
    for(; pos > 0; pos -= pos&-pos) ans += v[pos][op];
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int x,y;
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++) {
        cin >> x;
        update(i,x,0);
        update(i+1,-x,0);
    }

    for(int i = 1; i <= m; i++) 
        cin >> l[i] >> r[i] >> d[i];

    for(int i = 0; i < k; i++) {
        cin >> x >> y; 
        update(x,1,1);
        update(y+1,-1,1);
    }

    for(int i = 1; i <= m; i++) {
        x = query(i,1);
        update(l[i],x*d[i],0);
        update(r[i]+1,-x*d[i],0);
    }

    for(int i = 1; i <= n; i++) cout << query(i,0) << " ";
    cout << endl;

    return 0;
}

