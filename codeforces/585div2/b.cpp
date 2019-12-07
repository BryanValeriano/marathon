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
    ios_base::sync_with_stdio(false);
    int m; cin >> m;
    ll pos = 0;
    ll neg = 0;
    ll p = 0;
    ll n = 0;
    while(m) {
        int x; cin >> x;
        if(x > 0) {
            pos += p+1, p++;
            if(n) neg += n;
        } else {
            pos += n;
            neg += p+1, p++;
            swap(p,n);
        }
        m--;
    }
    cout << neg << " " << pos << endl;
    return 0;
}

