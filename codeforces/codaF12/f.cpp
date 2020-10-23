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
    int n,k,l,r,sa,sk,sz,z;
    cin >> n >> k >> l >> r >> sa >> sk;
    sz = sa-sk;
    z = n-k;

    if(k) {
        int eachk = sk/k;
        int totk = eachk*k;
        for(int i = 0; i < k; i++) {
            int x = (totk < sk? 1 : 0);
            totk += x;
            cout << eachk+x << " ";
        }
    }

    if(z) {
        int eachz = sz/z;
        int totz = eachz*z;
        for(int i = k; i < n; i++) {
            int x = (totz < sz? 1 : 0);
            totz += x;
            cout << eachz+x << " ";
        }
    }

    cout << endl;

    return 0;
}

