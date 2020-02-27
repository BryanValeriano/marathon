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

const int T = 2e5 + 5;
map<ii,int> qt;
ll a[T], b[T];
int n;

bool sameSig(int i) {
    return ((a[i] >= 0 and b[i] >= 0) or (a[i] < 0 and b[i] < 0));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    int ans = 0;
    int zeros = 0;

    for(int i = 0; i < n; i++) {
        if(a[i] != 0 and b[i] == 0) {
            qt[mk(0,0)]++;
            ans = max(ans,qt[mk(0,0)]);
        }
        else if(a[i] == 0 and b[i] == 0) zeros++;

        if(a[i] == 0 or b[i] == 0) continue;

        ll x, y, gcd;
        gcd = __gcd(abs(a[i]),abs(b[i]));
        x = abs(a[i]) / gcd;
        y = abs(b[i]) / gcd;

        if(sameSig(i)) qt[mk(-y,x)]++, ans = max(ans,qt[mk(-y,x)]);
        else qt[mk(y,x)]++, ans = max(ans,qt[mk(y,x)]);
    }

    cout << ans+zeros << endl;


    return 0;
}

