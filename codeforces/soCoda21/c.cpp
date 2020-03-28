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
const int T = 2e5 + 2;
int v[T];
int n,z;

bool check(int x) {
    for(int i = 0; i < x; i++)
        if(v[n-x+i] - v[i] < z) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> z;
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v,v+n);

    int l = 0;
    int ans = 0;
    int r = n/2;

    while(l <= r) {
        int mid = (l+r) >> 1;
        if(check(mid)) ans = mid, l = mid+1;
        else r = mid-1;
    }

    cout << ans << endl;

    return 0;
}

