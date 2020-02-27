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

const int T = 2e5 + 100;
int v[T], p[T];
vii qtd;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        qtd.eb(v[i],p[i]);
    }

    ll ans = 0;
    ll tot = 0;
    sort(qtd.begin(), qtd.end(), greater<ii>());
    priority_queue<int, vector<int> > pq;

    ii at = qtd.back();
    tot += at.se;
    pq.emplace(at.se);
    int last = at.fi;
    qtd.pop_back();

    while(qtd.size()) {
        at = qtd.back();
        qtd.pop_back();

        if(at.fi == last) {
            tot += at.se;
            pq.emplace(at.se);
            continue;
        }

        while(!pq.empty() and last++ < at.fi) {
            tot -= pq.top();
            ans += tot;
            cout << last-1 << " " << pq.top() << " | " << tot << " " << ans << endl;
            pq.pop();
        }

        tot += at.se;
        pq.emplace(at.se);

    }

    while(!pq.empty()) {
            tot -= pq.top();
            pq.pop();
            ans += tot;
        }

    cout << ans << endl;

    return 0;
}

