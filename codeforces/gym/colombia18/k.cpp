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

vector<double> v;
int n;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i = 0; i < n; i++) {
        int x; double y;
        cin >> x >> y;
        v.pb(x*y);
    }

    sort(v.begin(),v.end());
    double ans = 0;
    double acum = 0;
    for(int i = 0; i < n; i++) {
        acum += v[i];
        ans += acum;
    }
    
    cout << fixed << setprecision(6) << ans/n << endl; 
    return 0;
}

