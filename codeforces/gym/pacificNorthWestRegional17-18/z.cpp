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
    ll n; cin >> n;
    n++;
    while(1) {
        ll ok = n;
        int x = 0;
        while(ok) {
            x = ok%10;
            if(!x) break;
            ok /= 10;
        }
        if(!x) n++;
        else break;
    }
    cout << n << endl;
    return 0;
}

