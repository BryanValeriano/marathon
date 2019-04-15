#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

int solve(int x) {
    int base = 1;
    int ans = 0;
    while(x) {
        if(x%10 == 4) ans += base;
        base *= 10;
        x /= 10;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    int cont = 0;
    while(tc--) {
        int x; cin >> x;
        int y; y = solve(x);
        cout << "Case #" << ++cont <<": " << x-y << " " << y << endl;
    }
    return 0;
}

