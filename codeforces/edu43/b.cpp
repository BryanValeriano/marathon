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

ll n,m,k;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    if(k < n) { cout << k+1 << " " << 1 << endl; return 0; }
    k -= n;
    ll sob = k/(m-1);
    k -= sob*(m-1);
    ll lin = n - sob;
    ll col;
    if(!(sob&1)) col = 2 + k;
    else col = m-k;
    cout << lin << " " << col << endl;
    return 0;
}

