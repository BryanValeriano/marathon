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

bool can(int a, int b, int c) {
    if((b&1) && (c&1) && a) {
        a--;
        b--;
        c--;
    }
    b = b >>= 1;
    c = c >>= 1;
    return (a <= b+c);
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n,w1,w2,b1,b2,w,b;
        cin >> n >> w1 >> w2;
        cin >> w >> b;
        b1 = n-w1;
        b2 = n-w2;
        cout << (can(w,w1,w2) && can(b,b1,b2)? "yes" : "no") << endl;
    }
    return 0;
}

