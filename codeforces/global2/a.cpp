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

const int T = 3e5 + 5;
vector<int> c[T];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int x;

    for(int i = 1; i <= n; i++) {
        cin >> x;
        c[x].pb(i);
    }

    int ans = 0;

    for(int i = 1; i <= n; i++) {
        int far = n;
        for(int j = c[i].size()-1; j >= 0; j--) {
            if(c[i][j] == far) far--;
            else break;
        }
        if(c[i].size()) ans = max(ans, far - c[i][0]);
    }

    cout << ans << endl;

    return 0;
}

