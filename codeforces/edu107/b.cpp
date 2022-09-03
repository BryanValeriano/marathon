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
    int tc; cin >> tc;
    while(tc--) {
        int a,b,c; cin >> a >> b >> c;
        ll A, B, C;
        A = B = C = 1;
        a -= c, b -= c;
        while(--c) C *= 10ll;
        A = B = C;

        while(b--) {
            int tmp = log10(B);
            while((int)log10(B) == tmp) B *= 2ll;
        }
        while(a--) {
            int tmp = log10(A);
            while((int)log10(A) == tmp) A *= 5ll;
        }

        cout << A << " " << B << endl;
    }
    return 0;
}

