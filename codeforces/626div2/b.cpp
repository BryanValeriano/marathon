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
const int T = 4e4 + 2;
ll ok[T];

int main() {
    ios_base::sync_with_stdio(false);
    ll n,m,k;
    cin >> n >> m >> k;
    ll qtd = 0;

    while(n--) {
        int x; cin >> x;
        if(x) qtd++;
        else ok[qtd]++, qtd = 0;
    }

    ok[qtd]++;
    qtd = 0;
    ll wave = 0;
    for(int i = T-1; i > 0; i--) {
        qtd += wave;
        wave += ok[i];
        ok[i] += qtd;
        qtd = ok[i];
    }
    qtd = 0;
    ll ans = 0;
    ll last = 0;

    while(m--) {
        int x; cin >> x;
        if(x) {
            qtd++;
            ans += last;
            if((k%qtd)==0 and k/qtd < T) ans += ok[k/qtd], last += ok[k/qtd];
        } else qtd = 0, last = 0;
    }

    cout << ans << endl;
    return 0;
}

