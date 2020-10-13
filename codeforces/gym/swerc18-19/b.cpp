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
const int T = 1e5+5;
int x[T], y[T];

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];

    int l = 0;
    int r = 0;
    int ans = 0;
    multiset<int> bagx, bagy;
    bagx.insert(x[0]); bagy.insert(y[0]);

    while(l < n) {
        if(l) bagx.erase(bagx.find(x[l-1])), bagy.erase(bagy.find(y[l-1]));
        if(l > r) bagx.insert(x[l]), bagy.insert(y[l]);

        r = max(r,l);
        int maxx = *bagx.rbegin(), miny = *bagy.begin();
        while(r+1 < n and (r+1-l) <= (min(miny,y[r+1])-max(x[r+1],maxx))) {
            r++;
            bagx.insert(x[r]);
            bagy.insert(y[r]);
        }

        ans = max(ans,r-l+1);
        l++;
    }

    cout << ans << endl;
    return 0;
}

