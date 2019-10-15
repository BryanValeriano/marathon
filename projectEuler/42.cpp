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

const int T = 400;
bitset<T> ok;

int solve(string s) {
    int ans = 0;
    for(int i = 0; i < s.size(); i++) ans += s[i] - 'A' + 1;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int ans = 0; string s;
    for(int i = 1; (i*(i+1) >> 1) < T; i++) ok[i*(i+1)>>1] = 1;
    while(cin >> s) if(ok[solve(s)]) ans++;
    cout << ans << endl;
    return 0;
}

