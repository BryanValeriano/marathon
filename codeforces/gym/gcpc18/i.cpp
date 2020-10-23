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
const int T = 1e3+3;
int hs[T], vs[T];
int n;

bool check(int k) {
    for(int i = 0; i < n; i++) {
        if(hs[i]+k > vs[i]) return 1;
        if(hs[i]+k < vs[i]) return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0;i < n;i++) cin >> hs[i];
    for (int i = 0;i < n;i++) cin >> vs[i];
    int l = 0;
    int r = 1e3;
    int ans = 0;
    while(l <= r) {
        int mid = (l+r)>>1;
        if(check(mid)) ans = mid, r = mid-1;
        else l = mid+1;
    }
    cout << ans << endl;
    return 0;
}

