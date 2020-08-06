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
    int tc; cin >> tc;
    while(tc--) {
        int a,b,c,d;
        int x,y,x1,y1,x2,y2;
        cin >> a >> b >> c >> d;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        x = x+b-a;
        y = y+d-c;
        if(x1 == x2 and (a or b)) cout << "NO" << endl;
        else if(y1 == y2 and (c or d)) cout << "NO" << endl;
        else cout << (x >= x1 and x <= x2 and y >= y1 and y <= y2? "YES" : "NO") << endl;
    }
    return 0;
}

