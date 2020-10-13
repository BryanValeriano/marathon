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
vii ans;

void build(int x, int y) {
    ans.eb(x,y);
    ans.eb(x-1,y);
    ans.eb(x,y-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    ans.eb(0,0);
    ans.eb(0,1);
    ans.eb(1,1);
    ans.eb(1,0);
    int x = 1, y = 1;

    while(n--) {
        x++, y++;
        build(x,y);
    }

    cout << ans.size() << endl;
    for(ii z : ans) cout << z.fi << " " << z.se << endl;

    return 0;
}

