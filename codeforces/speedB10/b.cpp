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
const int T = 5e5 + 5;

int n;
vector<int> s;
bool ok[T];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        s.pb(x);
    }

    int at = 0;
    int ans = 0;

    for(int i = 1; i < n-1; i++) {
        if(s[i] != s[i-1] and s[i] != s[i+1]) at++, ok[i] = 1;
        else ans = max(ans, (at+1)/2), at = 0;
    }

    for(int i = 1; i < n-1; i++)
        if(ok[i]) s[i] = s[i-1];

    ans = max(ans, (at+1)/2), at = 0;

    cout << ans << endl;
    for(auto x : s) cout << x << " ";
    cout << endl;


    return 0;
}

