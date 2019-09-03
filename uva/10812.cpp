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

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        ll a,b;
        cin >> a >> b;
        if(!b or a == b) cout << a << " " << 0 << endl;
        else if((a&1) != (b&1) or b > a) cout << "impossible" << endl;
        else cout << b + (a-b)/2 << " " << (a-b)/2 << endl;
    }
    return 0;
}

