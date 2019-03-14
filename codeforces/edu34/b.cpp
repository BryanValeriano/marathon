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

int h1,h2,a1,a2,c1;

bool winN() {
    return (h2 - a1 <= 0);
}

bool surv() {
    return (h1 - a2 > 0);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin >> h1 >> a1 >> c1;
    cin >> h2 >> a2;

    vector<string>ans;
    
    while(!winN()) {
        if(surv()) {
            ans.pb("STRIKE");
            h2 -= a1;
        }
        else {
            ans.pb("HEAL");
            h1 += c1;
        }
        h1 -= a2;
    }
    ans.pb("STRIKE");
    cout << ans.size() << endl;
    for(auto x : ans) cout << x << endl;

	return 0;
}
