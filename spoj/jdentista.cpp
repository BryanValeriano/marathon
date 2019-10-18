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

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<ii> v;

    for(int i = 0; i < n; i++) {
        int a,b; cin >> a >> b;
        v.eb(b,a);
    }

    sort(v.begin(), v.end());

    int fim = 0;
    int ans = 0;
    for(int i = 0; i < v.size(); i++)
        if(v[i].se >= fim) ans++, fim = v[i].fi;
    cout << ans << endl;

    return 0;
}

