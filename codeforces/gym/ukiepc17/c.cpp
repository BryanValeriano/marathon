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
const int T = 8;
int v[T];

int main() {
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    int ans = 0, r = 0, maxi = 0;

    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        if(s[0] == 'r') r++;
        else if(s[0] == 'y') ans += 2, maxi = max(2,maxi);
        else if(s[0] == 'g') ans += 3, maxi = max(3,maxi);
        else if(s == "brown") ans += 4, maxi = max(4,maxi);
        else if(s == "blue") ans += 5, maxi = max(5,maxi);
        else if(s[0] == 'p') ans += 6, maxi = max(6,maxi);
        else ans += 7, maxi = max(maxi,7);
    }
    ans += r*maxi;
    if(ans) ans += r;
    else ans += min(r,1);
    cout << ans << endl;

    return 0;
}

