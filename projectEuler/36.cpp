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

const int T = 1e6;

string bin(int x) {
    string ans;
    while(x) {
        if(x&1) ans += '1';
        else ans += '0';
        x >>= 1;
    }
    return ans;
}

bool ok(int x, int op) {
    string s;
    if(!op) s = to_string(x);
    else s = bin(x);
    string t = s;
    reverse(t.begin(), t.end());
    return (s == t);
}

int main() {
    ios_base::sync_with_stdio(false);

    int ans = 0;

    for(int i = 1; i <= T; i++)
        if(ok(i,0) and ok(i,1)) ans += i;

    cout << ans << endl;

    return 0;
}

