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

int main() {
    ios_base::sync_with_stdio(false);
    int b,g,n; cin >> b >> g >> n;
    int ans = 0;

    for(int i = 0; i <= n; i++) {
        int bb = i;
        int gg = n-i;
        if(bb+gg == n and bb <= b and gg <= g) ans++;
    }
    cout << ans << endl;
    return 0;
}

