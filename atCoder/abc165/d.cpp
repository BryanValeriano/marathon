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
ll a,b,n;

ll calc(ll x) {
    return (a*x)/b - a*(x/b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> a >> b >> n;
    cout << calc(min(b-1,n)) << endl;
    return 0;
}

