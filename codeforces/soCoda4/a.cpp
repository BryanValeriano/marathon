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
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

vii ans;

int main() {
    ios_base::sync_with_stdio(false);
    ll n,k; cin >> n >> k;

    if(n > k*(k-1)) { cout << "NO" << endl; return 0; }

    int x = 1, y = 2;

    while(n--) {
        ans.eb(x,y);
        x++;
        x %= (k+1);
        if(!x) x++;

        if(x == 1) y += 2;
        else y++;

        y %= (k+1);
        if(!y) y++;
    }

    cout << "YES" << endl;
    for(auto z : ans) cout << z.fi << " " << z.se << endl;


    return 0;
}

