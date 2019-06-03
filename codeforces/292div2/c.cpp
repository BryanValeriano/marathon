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

int primos[4] = {2,3,5,7};

int main() {
    ios::sync_with_stdio(false);
    string ans;

    int n; cin >> n;
    char x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        int xx = x - '0';
        if(xx <= 1) continue;
        if(xx == 2 or xx == 3 or xx == 5 or xx == 7) ans += x;
        if(xx == 4) ans += "322";
        if(xx == 6) ans += "53";
        if(xx == 8) ans += "7222";
        if(xx == 9) ans += "7332";
    }

    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    return 0;
}

