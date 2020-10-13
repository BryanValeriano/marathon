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
typedef tuple<int,int,int> ti;
typedef vector<ti> vti;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e6+5;
const int N = 1e3;
vti v;
int s[T], best[T];

bool tent(int t, int x, int y, int i) {
    int tt,xx,yy;
    tie(tt,xx,yy) = v[i];
    return (t-tt >= (abs(x-xx)+abs(y-yy)));
}

int main() {
    ios_base::sync_with_stdio(false);
    int r,n; cin >> r >> n;
    int ans = 1;
    v.eb(0,1,1);
    s[0] = best[0] = 1;

    for(int i = 1; i <= n; i++) {
        int t,x,y; cin >> t >> x >> y;
        int tmp = 0;
        tmp = (i-N >= 0? best[i-N]+1 : 0);
        for(int j = max(0,i-N+1); j < v.size(); j++)
            if(s[j] and tent(t,x,y,j))
                tmp = max(tmp,s[j]+1);
        best[i] = max(best[i-1],tmp);
        s[i] = tmp;
        ans = max(ans,tmp);
        v.eb(t,x,y);
    }

    cout << ans-1 << endl;
    return 0;
}

