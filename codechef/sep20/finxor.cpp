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
const int T = 1e6;
const int N = 25;
ll qtd[N];
const double PI = acos(-1.0);

void query(int x) {
    cout << 1 << " " << x << endl << flush;
}

int main() {
    //ios_base::sync_with_stdio(false);
    int tc; cin >> tc;

    while(tc--) {
        ll n; cin >> n;
        ll ans = 0;

        query(1);
        ll last, at, first;
        cin >> last;
        first = last;
        ll sum = 1;

        for(ll i = 2,bit = 1; i < T; i <<= 1, bit++) {
            sum += i;
            query(sum);
            cin >> at;
            ll dif = (at-last);
            ll tot = n*i;
            qtd[bit] = (tot-dif)/(i*2);
            last = at;
        }

        sum = 0;
        for(ll i = 2,bit = 1; i < T; i <<= 1, bit++)
            sum += qtd[bit]*i;

        qtd[0] = n-(first-sum);

        for(ll i = 1,bit = 0; i < T; i <<= 1, bit++) {
            ans += (qtd[bit]&1? i : 0);
            //cout << i << " " << qtd[bit] << endl << flush;
        }

        cout << 2 << " " << ans << endl << flush;
        int ok;
        cin >> ok;
        if(ok==-1) return 0;
    }

    return 0;
}

