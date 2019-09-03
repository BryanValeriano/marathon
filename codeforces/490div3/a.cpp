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
const int T = 110;
int v[T];

int main() {
    ios::sync_with_stdio(false);
    int n,k; cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> v[i];
    int l = 0; int r = n-1;
    int ans = 0;

        while(l <= r) {
        if(v[l] <= k) { ans++; l++; }
        else if(v[r] <= k) { ans++; r--; }
        else break;
    }
    cout << ans << endl;
    return 0;
}

