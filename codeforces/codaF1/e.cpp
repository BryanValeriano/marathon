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
int n,k;
vector<int> v;
vector<string> in;
vector<string> perm;

void arrange() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < k; j++)
            perm[i][j] = in[i][v[j]];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        in.pb(s);
        perm.pb(s);
    }
    for(int i = 0; i < k; i++) v.pb(i);
    ll ans = INF;
    do {
        arrange();
        sort(perm.begin(),perm.end());
        ll mini = stoi(*perm.begin());
        ll maxi = stoi(*perm.rbegin());
        ans = min(ans,maxi-mini);
    } while(next_permutation(v.begin(), v.end()));
    cout << ans << endl;
    return 0;
}

