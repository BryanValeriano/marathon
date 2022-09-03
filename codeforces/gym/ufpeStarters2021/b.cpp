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
const int T = 22;
vector<int> v[T];

bool check(int mask, int n) {
    bool ans = 1;
    for(int i = 1; i <= n; i++) {
        bool hasImpostor = 0;
        for(int j = 0; j < v[i].size(); j++) {
            hasImpostor |= (mask & (1<<(v[i][j]-1)));
        }
        if(mask & (1<<(i-1))) ans &= (!hasImpostor);
        else ans &= hasImpostor;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int lim = 1<<n;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int s; cin >> s;
        for(int j = 0; j < s; j++) {
            int x; cin >> x;
            v[i].pb(x);
        }
    }
    for(int mask = 0; mask < lim; mask++)
        ans += check(mask,n);
    cout << ans << endl;
    return 0;
}

