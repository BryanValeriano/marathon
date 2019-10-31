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

const int T = 40;
ll cal[T];
ll fib[T];

int main() {
    ios_base::sync_with_stdio(false);
    cal[0] = cal[1] = 1;
    fib[1] = 1;
    for(int i = 2; i < T; i++) {
        fib[i] = fib[i-1]+fib[i-2];
        cal[i] = cal[i-1]+cal[i-2]+1;
    }
    int tc; cin >> tc;
    while(tc--) {
        int x; cin >> x;
        cout << "fib(" << x << ") = " << cal[x]-1 << " calls = " << fib[x] << endl;
    }
    return 0;
}

