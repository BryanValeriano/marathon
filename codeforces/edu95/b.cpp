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
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 110;
int v[T];
int ok[T];

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        vector<int> ve;

        for(int i = 0; i < n; i++) cin >> v[i];
        for(int i = 0; i < n; i++) {
            cin >> ok[i];
            if(!ok[i]) ve.pb(v[i]);
        }
        sort(ve.begin(),ve.end(),greater<int>());
        int l = 0;
        for(int i = 0; i < n; i++) {
            if(!ok[i]) v[i] = ve[l++];
            cout << v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

