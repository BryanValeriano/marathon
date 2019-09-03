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

int main() {
    ios::sync_with_stdio(false);
    ll t, a, b, k;
    cin >> t;
    while(t--) {
        cin >> a >> b >> k;
        ll dif = a - b;
        if(k%2 == 0) cout << dif * (k/2) << endl; 
        else cout << (dif * (k/2)) + a << endl;
    }

    return 0;
}

