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

int main() {
    ios_base::sync_with_stdio(false);
    int t,s,q; cin >> t >> s >> q;
    int ans = 1;
    int time = 0;
    int seconds = 0;

    while(time < t) {
        seconds++;
        if(seconds > 1) s++;
        if(seconds == q) seconds = 0;
        if(time < s) time++;
        else time = 1,ans++;
    }

    cout << ans << endl;

    return 0;
}

