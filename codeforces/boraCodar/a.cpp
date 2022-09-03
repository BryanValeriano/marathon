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

bool isPrime(ll x) {
    for(ll i = 2; i*i <= x; i++) {
        if(x%i==0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        ll x,y; cin >> x >> y;
        cout << (x-y==1?"YES":"NO") << endl;
    }
    for(ll i = 2; i < 400; i++) {
        if(!isPrime(i*i - (i-1)*(i-1))) {
            cout << i << endl;
        }
    }
    return 0;
}

