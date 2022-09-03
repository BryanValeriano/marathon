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
    ll h,w; cin >> h >> w;
    if(h == 1 or w == 1) {
        cout << 1 << endl;
        return 0;
    }
    ll qtdPerRow1 = (w/2) + (w%2);
    ll qtdPerRow2 = (w/2);
    ll qtdRow1 = (h/2) + (h%2);
    cout << (qtdRow1*qtdPerRow1 + (h-qtdRow1)*qtdPerRow2) << endl;
    return 0;
}

