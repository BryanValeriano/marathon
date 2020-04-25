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
typedef pair<int,double> id;
typedef vector<ii> vii;
typedef vector<id> vid;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);


int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vid v;

    for(int i = 0; i < n; i++) {
        int x; double z;
        cin >> x >> z;
        v.eb(x,z);
    }

    sort(v.begin(), v.end());
    double L = 0;

    for(int i = 1; i < n; i++)
        L = max(L, fabs(v[i].se-v[i-1].se)/abs(v[i].fi-v[i-1].fi));

    cout << fixed << setprecision(4) << L << endl;
    return 0;
}

