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
const int T = 20;
int v[T];
int p[T];

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    p[0] = 1;
    for(int i = 1; i < T; i++) p[i] = 2*p[i-1];

    while(tc--) {
        int n,w; cin >> n >> w;
        memset(v,0,sizeof v);
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            v[(int)log2(x)]++;
        }
        int bag = n;
        int h = 0;
        while(bag) {
            h++;
            int tmp = w;
            for(int i = T-1; i >= 0; i--) {
                while(v[i] && p[i] <= tmp) {
                    v[i]--;
                    bag--;
                    tmp -= p[i];
                }
            }
        }
        cout << h << endl;
    }
    return 0;
}

