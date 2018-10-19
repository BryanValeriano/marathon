#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while(tc--) {
        ll s, a, b, c;
        cin >> s >> a >> b >> c;
        ll qts = s/c;
        ll B = (qts/a)*b;
        ll rest = s%c;
        rest = rest/c;
        //cout << B << " " << rest  << " " << qts << endl;
        cout << qts + B + rest << endl;
    }
    return 0;
}

