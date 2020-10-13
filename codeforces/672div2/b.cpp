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
const int T = 32;
ll freq[T];

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        for(int i = 0; i < T; i++) freq[i] = 0;
        while(n--) {
            int x; cin >> x;
            for(int i = 31; i >= 0; i--) {
                if(x&(1<<i)) {
                    freq[i]++;
                    break;
                }
            }
        }
        ll ans = 0;
        for(int i = 0; i < T; i++)
            ans += (freq[i]*(freq[i]-1))>>1;
        cout << ans << endl;
    }
    return 0;
}

