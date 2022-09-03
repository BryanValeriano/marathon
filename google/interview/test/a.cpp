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

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int ans = 101;
    while(n--) {
        int x; cin >> x;
        ans = min(ans,x);
    }
    cout << ans << endl;
    return 0;
}

