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
const ll MOD = 1e9 + 7;

const int T = 1e5 + 5;
ll a[T], b[T];
ll n,k,x;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> x;
    a[0] = (x == 1? 1 : 0);
    b[0] = (x == 1? 0 : 1);
    for(int i = 1; i < n; i++) {
        a[i] = b[i-1];
        b[i] = ((a[i-1]*(k-1) % MOD) + (b[i-1]*(k-2)%MOD))%MOD;
    }

    cout << a[n-1] << endl;
    return 0;
}

