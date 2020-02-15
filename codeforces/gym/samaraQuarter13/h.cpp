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
    ios_base::sync_with_stdio(false);

    int n;
    string a, b;
    cin >> n >> a >> b;
    for (int i = 0;i < n;i++) {
        a[i] = (int)(a[i] == b[i]) + '0';
    }
    int ans = 0, cnt = 0;
    for (int i = 0;i < n;i++) {
        if (a[i] == '0') cnt++;
        else if (cnt) {
            ans++;
            cnt = 0;
        }
    }
    if (cnt) ans++;
    cout << ans << endl;
    
    return 0;
}

