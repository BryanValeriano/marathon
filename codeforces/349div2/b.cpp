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
const int T = 1e5+2;
ll v[T];

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v,v+n);

    ll wat = v[n-1];
    for(int i = 0; i < n-1; i++) wat -= v[i];
    cout << max(0ll,wat+1) << endl;

    return 0;
}

