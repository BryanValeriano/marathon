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

int solve(int x) {
    int ans = 0;
    while(x) {
        ans += x%10;
        x /= 10;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int a,b; cin >> a >> b;
    int sa = 0;
    int sb = 0;
    sa = solve(a);
    sb = solve(b);
    cout << max(sa,sb) << endl;
    return 0;
}

