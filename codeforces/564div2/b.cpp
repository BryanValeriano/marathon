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

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int ans = n/2;
    ans++;
    int base = n-ans;
    base = ans-base+1;
    cout << ans << endl;
    for(int i = 1; i <= ans; i++) cout << 1 << " " << i << endl;
    for(int i = base; i <= ans; i++) cout << ans << " " << i << endl;
    return 0;
}

