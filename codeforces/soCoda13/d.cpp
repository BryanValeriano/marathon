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

bool almost(int x) {
    int q = 0;
    for(int i = 2; i <= x; i++) {
        if(x % i == 0) {
            q++;
            while(x % i == 0) x /= i;
        }
    }
    return q == 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int ans = 0;
    for(int i = 6; i <= n; i++)
        if(almost(i)) ans++;
    cout << ans << endl;
    return 0;
}

