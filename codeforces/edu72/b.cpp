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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
ll n,x;
ll guloso;
ll fatal;

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        fatal = guloso = 0;
        cin >> n >> x;
        ll a,b;
        while(n--) {
            cin >> a >> b;
            fatal = max(fatal,a);
            guloso = max(guloso, a-b);
        }

        if(fatal >= x) { cout << 1 << endl; continue; }
        if(guloso <= 0) { cout << -1 << endl; continue; }
        ll rest = (x-fatal) % guloso ? 1 : 0;
        cout << (x-fatal)/guloso + rest + 1 << endl;
    }



    return 0;
}

