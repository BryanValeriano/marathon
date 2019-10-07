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

const int T = 10;
ll v[T];

int ok(int x) {
    int ans = 0;
    int z = x;
    while(x) {
        ans += v[x%10];
        x /= 10;
    }
    if(z == ans) { cout << z << endl; return z; }
    return 0;
}


int main() {
    ios_base::sync_with_stdio(false);
    int ans = 0;
    for(int i = 1; i <= 9; i++) v[i] = pow(i,5);
    for(int i = 4000; i <= 1000000; i++) ans += ok(i);
    cout << ans << endl;
    return 0;
}

