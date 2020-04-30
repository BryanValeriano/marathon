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
typedef pair<ll,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 2e5 + 3;
int off[T];
int ans[T];
int skill[T];

int main() {
    ios_base::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    vii v;

    for(int i = 1; i <= n; i++)
        cin >> skill[i], v.eb(skill[i],i);

    while(k--) {
        int x,y; cin >> x >> y;
        if(skill[x] > skill[y]) off[x]++;
        if(skill[x] < skill[y]) off[y]++;
    }

    sort(v.begin(),v.end());
    int last = -1;
    int strike = 0;

    for(int i = 0; i < n; i++) {
        if(v[i].fi == last) strike++;
        else strike = 0;
        ans[v[i].se] = i-off[v[i].se]-strike;
        last = v[i].fi;
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}

