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
const int T = 1e5+3;
int a[T];

int main() {
    ios_base::sync_with_stdio(false);
    int h,w; cin >> h >> w;
    double ans = INF;
    for(int i = 0; i < h; i++) cin >> a[i];
    for(int i = 0; i < h; i++) {
        int x; cin >> x;
        ans = min(ans, ((double)(w-a[i]-x))/2);
    }
    cout << ans << endl;
    return 0;
}

