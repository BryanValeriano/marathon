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

ll result = 1;
ll ans = 0;
bool bonus;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        if(x == 0) bonus = 1, ans++;
        else if(x >= 1) ans += (x-1);
        else ans += abs(x)-1, result *= -1;
    }

    if(result == 1) cout << ans << endl;
    else cout << (bonus? ans : ans + 2) << endl;

    return 0;
}

