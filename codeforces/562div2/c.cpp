#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 3e5 + 5;
int v[T];
int ve[T];
int n,k;

bool check(int x) {
    bool ok = 1;
    for(int i = 1; i <= n; i++) {
        if(v[i] < ve[i-1]) {
            if(ve[i-1] - v[i] <= x) ve[i] = ve[i-1];
            else return false;
        } else {
            int dist = ve[i-1] + (k-v[i]);
            if(dist <= x) ve[i] = ve[i-1];
            else ve[i] = v[i];
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> v[i];

    int l = 0;
    int r = k;
    int ans = k;


    while(l <= r) {
        int mid = (l+r) >> 1;
        if(check(mid)) ans = mid, r = mid-1;
        else l = mid+1;
    }
    cout << ans << endl;

    return 0;
}

