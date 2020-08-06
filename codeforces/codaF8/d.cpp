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

int main() {
    ios_base::sync_with_stdio(false);
    int a,b,c,d; cin >> a >> b >> c >> d;
    cout << (a!=c)+(b!=d) << " ";
    int blk = ((a&1) != (b&1)? 1 : 0);
    int blk2 = ((c&1) != (d&1)? 1 : 0);
    if(blk != blk2) cout << 0 << " ";
    else cout << ((a-b)!=(c-d))+((a+b)!=(c+d)) << " ";
    cout << max(abs(a-c),abs(b-d)) << endl;
    return 0;
}

