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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        ll n,k,d1,d2;
        ll rest;
        cin >> n >> k >> d1 >> d2;
        d2 += d1;

        rest = n-k;

        ll vez = rest/3;
        ll sobra = rest%3;

        while(sobra and (d1 or d2)) {
            if(d1 > d2) d1--, sobra--, rest--;
            else if(d2 > 0) d2--, sobra--, rest--;
        }
        if(d1 > vez*2 or d2 > vez*2) { cout << "no" << endl; continue; }

    }
    return 0;
}

