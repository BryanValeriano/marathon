#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 55;
bool vis[T];
int pos[T];
vector<int> v;
vector<int> pre;

void change(int pos) {
    int tmp = v[pos];
    for(int i = pos; i > 0; i--) v[i] = v[i-1];
    v[0] = tmp;
}

int solve(int x) {
    int tmp = pos[x];
    int ans = 0;
    for(int i = 0; i < pre.size(); i++) {
        ans += pre[i] > tmp;
    }
    pre.pb(tmp);
    return tmp+ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,q; cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        if(vis[x]) continue;
        pos[x] = i;
        vis[x] = 1;
        v.pb(x);
    }
    memset(vis, 0, sizeof vis);

    while(q--) {
        int x; cin >> x;
        for(int i = 0; i < T; i++) {
            if(v[i] == x) {
                if(vis[x]) cout << i+1 << " ";
                else cout << solve(x) << " ";
                change(i);
                vis[x] = 1;
                break;
            }
        }
    }
    return 0;
}

