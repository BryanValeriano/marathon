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

const int T = 2e5 + 3;
int v[T];

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    if(n&1) {
        cout << "YES" << endl;
        int l = 1;
        int r = 2*n;
        int i = 0;
        int ok = 2*n + 1;
        while(i < n) {
            v[i] = l, v[(i+n)%ok] = l+1;
            i++, l += 2;
            if(i == n) break;
            v[i] = r, v[(i+n)%ok] = r-1;
            i++, r -=2;
        }
        for(int i = 0; i < 2*n; i++) cout << v[i] << " ";
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

