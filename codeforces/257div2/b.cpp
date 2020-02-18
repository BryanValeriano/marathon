#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;
const ll MOD = 1e9 + 7;
 
int main() {
    ios_base::sync_with_stdio(false);
    ll f[7], n;
    cin >> f[0] >> f[1] >> n;
    n--;
    for(int i = 2; i < 6; i++) f[i] = (f[i-1] - f[i-2]) % MOD;
    cout << (f[n%6]+MOD)%MOD << endl;
    return 0;
}

