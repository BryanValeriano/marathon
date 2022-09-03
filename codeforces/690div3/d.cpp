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
const int T = 3e3+4;
ll v[T];
int n;

bool ok(ll alvo) {
    ll at = 0;
    for(int i = 0; i < n; i++) {
        at += v[i];
        if(at > alvo) return 0;
        if(at == alvo) at = 0;
    }

    return at==0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        ll sum = 0;
        cin >> n;
        for(int i = 0; i < n; i++) cin >> v[i], sum += v[i];
        for(ll i = n; i >= 1; i--) {
            if(sum%i) continue;
            if(ok(sum/i)) {
                cout << n-i << endl;
                break;
            }
        }
    }
    return 0;
}

