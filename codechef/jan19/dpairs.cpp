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
set<ll> id;
ii a[T];
ii b[T];

bool cmp(const ii &x, const ii &y) {
    if(x.fi != y.fi) return x.fi < y.fi;
    else return false;
}

int main() {
    ios::sync_with_stdio(false);
    int n,m,x;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> x;
        a[i] = mk(x,i);
    }

    for(int i = 0; i < m; i++) {
        cin >> x;
        b[i] = mk(x,i);
    }

    sort(a, a+n, cmp);
    sort(b, b+m, cmp);

    int moves = 0; 
    int fim = n;

    for(int i = 0; i < fim && moves < n+m-1; i++) {
        fim--;
        for(int j = 0; j < m && moves < n+m-1; j++) {
            if(! id.count(a[i].fi + b[j].fi)) {
                cout << a[i].se << " " << b[j].se << endl;
                moves++;
                id.insert(a[i].fi + b[j].fi);
            }
        }
        for(int j = 0; j < m && moves < n+m-1; j++) {
            if(! id.count(a[fim].fi + b[j].fi)) {
                cout << a[fim].se << " " << b[j].se << endl;
                moves++;
                id.insert(a[fim].fi + b[j].fi);
            }
        }
    }



    return 0;
}

