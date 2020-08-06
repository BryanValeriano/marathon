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
const int T = 11;
ll p[T], c[T];

int main() {
    ios_base::sync_with_stdio(false);
    ll d,g; cin >> d >> g;
    g /= 100;

    for(int i = 0; i < d; i++) {
        cin >> p[i] >> c[i];
        c[i] /= 100;
    }

    int gol = (1<<d);
    ll ans = INF;

    for(ll mask = 0; mask < gol; mask++) {
        ll points = 0;
        ll solve = 0;
        for(ll j = 0; j < d; j++) {
            if(mask&(1<<j)) {
                solve += p[j];
                points += (j+1)*p[j]+c[j];
            }
        }
        for(ll j = d-1; j >= 0 and points < g; j--) {
            if(mask&(1<<j)) continue;
            ll ok = 0;
            while(ok < p[j] and points < g) {
                points += (j+1);
                solve++;
                ok++;
            }
            if(ok == p[j]) points += c[j];
        }
        if(points >= g) ans = min(ans,solve);
    }

    cout << ans << endl;

    return 0;
}

