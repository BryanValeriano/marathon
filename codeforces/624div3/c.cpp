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

const int T = 2e5 + 5;
ll v[T];
ll ans[26];
int n,m;
string s;

void init(int n) {
    for(int i = 0; i <= n; i++) v[i] = 0;
    for(int i = 0; i < 26; i++) ans[i] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> m >> s;
        init(n);
        s = "#" + s;

        while(m--) {
            int r; cin >> r;
            v[0]++;
            v[r+1]--;
        }

        for(int i = 1; i <= n; i++) {
            v[i] += v[i-1];
            ans[s[i]-'a'] += v[i]+1;
        }

        for(int i = 0; i < 26; i++) cout << ans[i] << " ";
        cout << endl;

    }

    return 0;
}

