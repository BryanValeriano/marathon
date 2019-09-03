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
    ll k,n; cin >> n >> k;
    ll id;
    ll first = INF;
    ll x,y;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        if(x < k) {
            ll vezes = (k-x)/y;
            if((k-x) % y != 0) vezes++;
            x += vezes*y;
        }
        if(x < first) {
            first = x;
            id = i+1;
        }
    }

    cout << id << endl;

    return 0;
}

