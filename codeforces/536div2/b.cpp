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

const int T = 1e5 + 3;

int n,m;
ll price[T];
ll qtd[T];
vector<ii> v;
ll point;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;

    for(int i = 1; i <= n; i++) cin >> qtd[i];
    for(int i = 1; i <= n; i++) {
        cin >> price[i];
        v.eb(price[i],i);
    }

    sort(v.begin(), v.end());
    ll a,b;
    bool flag = 0;

    while(m--) {
        ll pagou = 0;
        cin >> a >> b;
        ll pode = min(qtd[a], b);
        qtd[a] -= pode;
        b -= pode;
        pagou += pode*price[a];
        while(b && (!flag)) {
            if(point == n) { flag = 1; continue; }
            pode = min(qtd[v[point].se], b);
            b -= pode;
            pagou += pode * price[v[point].se];
            qtd[v[point].se] -= pode;
            if(!qtd[v[point].se]) point++;
        }
        cout << (flag? 0 : pagou) << endl;
    }

    return 0;
}

