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

int main() {
    ios::sync_with_stdio(false);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<int> ans;
    for(int i = 1; i*i <= c; i ++) {
        if(c % i == 0) {
            int aux = c/i;
            if(i % a == 0 and i % b != 0 and d % i != 0)
                ans.pb(i);
            if(aux % a == 0 and aux % b != 0 and d % aux != 0)
                ans.pb(aux);
        }
    }
    sort(ans.begin(), ans.end());
    if(ans.size() == 0) cout << -1 << endl;
    else cout << *ans.begin() << endl;

    return 0;
}

