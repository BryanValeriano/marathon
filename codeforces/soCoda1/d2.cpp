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
const int T = 2e5 + 5;

int m,n,k,t;
int a[T];
int l[T], r[T], d[T];
int need[T];

bool check(int agi) {
    memset(need, 0, sizeof need);

    for(int i = 0; i < k; i++)
        if(d[i] > agi) need[l[i]]++, need[r[i]+1]--;

    int ans = n+1;

    for(int i = 1; i <= n+1; i++) {
        need[i] += need[i-1];
        if(need[i]) ans += 2;
    }

    return ans <= t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> m >> n >> k >> t;
    for(int i = 0; i < m; i++) cin >> a[i];
    for(int i = 0; i < k; i++) cin >> l[i] >> r[i] >> d[i];

    int l = 0;
    int r = 2e5 + 10;

    int maxi = INF, ans = 0;

    while(l <= r) {
        ll mid = (l+r) >> 1;
        if(check(mid)) maxi = mid, r = mid-1;
        else l = mid+1;
    }

    for(int i = 0; i < m; i++) ans += (maxi <= a[i]);
    cout << ans << endl;

    return 0;
}

