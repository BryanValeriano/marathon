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
typedef pair<int,int> ii;
typedef tuple<int,int,int> ti;
typedef vector<ti> vti;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 2e5+5;
int ans[T];
vti v;

int main() {
    ios_base::sync_with_stdio(false);
    memset(ans,INF,sizeof ans);
    ans[0] = 0;
    int n,m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int x,y; cin >> x >> y;
        v.eb(x-y,x,y);
    }
    sort(v.begin(),v.end());

    for(auto &[ignore,x,y] : v) {
        for(int i = 0; i <= m; i++) {
            int bordaEsq = max(1,x-y-i);
            int bordaDir = min(m,x+y+i);
            ans[bordaDir] = min(ans[bordaDir],ans[bordaEsq-1]+i);
        }
        for(int i = m-1; i >= 0; i--) ans[i] = min(ans[i],ans[i+1]);
    }

    cout << ans[m] << endl;

    return 0;
}

