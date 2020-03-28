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

vector<ll> v;
double eps = 1e-6;

int main() {
    ios_base::sync_with_stdio(false);
    ll n,a,b; cin >> n >> a >> b;
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        v.pb(x);
    }
    ll sum = 0;
    ll qtd = 0;
    sort(v.begin(),v.end(),greater<ll>());
    ll last;
    int ways = 0;

    for(int i = 0; i < n; i++) {
        if(i < a) {
            qtd++;
            sum += v[i];
            last = v[i];
        } else {
            double x = (double)sum/(double)qtd;
            double y = (double)(sum+v[i])/(double)(qtd+1);
            if(x > y+eps) break;
            qtd++;
            sum += v[i];
            last = v[i];
        }
    }

    for(int i = 0; i < n; i++) ways += (v[i] == last);
    cout << fixed << setprecision(6) << ((double)sum/(double)qtd) << endl;
    cout << ways << endl;

    return 0;
}

