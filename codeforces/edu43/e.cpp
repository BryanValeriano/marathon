#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<ll,int> ii;
const ll INF = 0x3f3f3f3f3f3f3f;
const double PI = acos(-1.0);

const int T = 2e5 + 2;
ll hp[T];
ll dmg[T];
bool choose[T];
vector<ii> best;
ll n;
ll a,b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> a >> b;

    ll nova = 1;
    for(int i = 1; i <= a; i++) nova *= 2ll;
    ll mini = INF;
    ll ans = 0;
    ll ajuda = 0;
    ll tot = 0;

    for(int i = 0; i < n; i++) {
        cin >> hp[i] >> dmg[i];
        best.eb(max(0ll,hp[i] - dmg[i]), i);
        tot += dmg[i];
    }

    sort(best.begin(), best.end(), greater<ii>());

    for(int i = 0; i < min(n,b); i++) {
        mini = min(mini, best[i].fi);
        choose[best[i].se] = 1;
        ajuda += best[i].fi;
    }

    if(b > n) mini = 0;
    ans = tot+ajuda;

    for(int i = 0; i < n; i++) {
        ll ok = ajuda;
        ll nok = tot;
        nok -= dmg[i];

        if(choose[i]) ok -= max(0ll,hp[i] - dmg[i]);
        else ok -= mini;

        if(b) nok += hp[i]*nova;

        ans = max(ans, nok+ok);
    }

    cout << ans << endl;
    return 0;
}

