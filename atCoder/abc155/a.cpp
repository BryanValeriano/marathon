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
    vector<int> v;

    for(int i = 0; i < 3; i++) {
        int x; cin >> x;
        v.pb(x);
    }

    sort(v.begin(), v.end());

    cout << ((v[0] == v[1] and v[0] != v[2]) or (v[1] == v[2] and v[0] != v[2])? "Yes" : "No") << endl;



    return 0;
}

