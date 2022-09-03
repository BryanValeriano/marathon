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
const int T = 2e5+5;
ll v[T];

int main() {
    ios_base::sync_with_stdio(false);
    int n,x;
    cin >> n >> x;
    while(n--) {
        int s,d; cin >> s >> d;
        v[s]++;
        v[s+d+1]--;
    }

    for(int i = 1; i < T; i++) v[i] += v[i-1];
    ll ans = 2e18;
    int start = 0;

    for(int i = 0; i <= 480; i++) {
        ll tmp = 0;
        for(int j = i; j < T; j += x) tmp += v[j];
        if(tmp < ans) {
            ans = tmp;
            start = i;
        }
    }
    cout << start << " " << ans << endl;
    return 0;
}

