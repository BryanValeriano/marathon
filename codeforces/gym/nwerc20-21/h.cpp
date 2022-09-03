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
const int T = 1e5+5;
int v[T];
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v,v+n);
    int l = 0; int r = n-1;
    int pos = 0;
    while(l <= r) {
        ans.pb(pos&1? v[r--] : v[l++]);
        pos++;
    }
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < n; i++) cout << ans[i] << (i+1 < n? ' ' : '\n');
    return 0;
}

