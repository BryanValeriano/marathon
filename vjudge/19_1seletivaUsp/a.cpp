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
    int tc; cin >> tc;
    while(tc--) {
        ll a,b,c;
        cin >> a >> b >> c;
        ll maxi = (a+b)*4LL;
        ll mini = ((max(0LL, a - (b*2))) + b) * 4LL;
        if(c >= mini and c <= maxi and !(c % 4)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}

