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

int main() {
    ios_base::sync_with_stdio(false);
    ll s,p,y,j;
    ll corn = 0;
    while(cin >> s) {
        cin >> p >> y >> j;
        ll ye = ((12+j)-(y+p))/3;
        corn = (((12+j)-(y+p))%3);
        ll puf = ye+p;
        ll sp = ye+y;
        cout << sp+(corn>0) << " " << puf+(corn>1) << " " << ye << endl;
    }
    return 0;
}

