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

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int last = 0, ans = 0, tmp = 0;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(last*2 >= x) tmp++;
        else tmp = 1;
        ans = max(tmp,ans);
        last = x;
    }
    cout << ans << endl;
    return 0;
}

