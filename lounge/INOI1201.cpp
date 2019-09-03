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
const int T = 2e5 + 10;
int n;
ii v[T];

bool cmp(ii &a, ii &b) {
    if(a.se != b.se) return a.se > b.se;
    return false;
}

ll solve() {
    ll acum = 0;
    ll last = 0;
    for(int i = 0; i < n; i++) {
        ll atual = acum + v[i].fi + v[i].se;
        last = max(last, atual);
        acum += v[i].fi;
    }
    return last;
}

void read() {
    cin >> n;
    int a,b,c;
    for(int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        v[i] =  mk(a, b+c);
    }
    sort(v, v + n, cmp);
}

int main() {
    ios::sync_with_stdio(false);
    read();
    cout << solve() << endl;
    return 0;
}

