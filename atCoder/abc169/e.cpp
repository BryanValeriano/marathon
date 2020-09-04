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

int main() {
    ios_base::sync_with_stdio(false);
    vector<ll> mini, maxi;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int a,b; cin >> a >> b;
        mini.pb(a);
        maxi.pb(b);
    }
    sort(mini.begin(),mini.end());
    sort(maxi.begin(),maxi.end());
    ll x = (n&1? maxi[n/2]-mini[n/2]+1 : (maxi[n/2-1]+maxi[n/2])-(mini[n/2-1]+mini[n/2])+1);
    cout << x << endl;
    return 0;
}

