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
const int T = 102;
bool v[T];

int main() {
    ios_base::sync_with_stdio(false);
    int n,k; cin >> n >> k;
    while(k--) {
        int x; cin >> x;
        while(x--) {
            int y; cin >> y;
            if(!v[y]) n--;
            v[y] = 1;
        }
    }
    cout << n << endl;
    return 0;
}

