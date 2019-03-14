#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x) cout << #x << " = " << x << endl
#define ok cout << "ok" << endl

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
	ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> v;
    int x;
    int ans = 1;
    int maxi = 1;
    for(int i = 0; i < n; i++) {
        cin >> x;
        v.pb(x);
    }
    sort(v.begin(), v.end());
    for(int i = 1; i < n; i++) {
        if(v[i] == v[i-1]) ans++;
        else {
            maxi = max(ans, maxi);
            ans = 1;
        }
    }
    maxi = max(ans, maxi);
    
    cout << maxi << endl;
	return 0;
}
