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

const int T = 55;
ll f[T];

int main() {
    ios_base::sync_with_stdio(false);
    f[0] = 0; f[1] = 1;
    for(int i = 2; i < T; i++) f[i] = f[i-1] + i + (i&1);
    int tc; cin >> tc;
    while(tc--) { int x; cin >> x; cout << f[x] << endl; }
    return 0;
}

