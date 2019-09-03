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
    int n; cin >> n;
    vii caps;
    int a,b;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        caps.eb(a,b);
    }
    int k; cin >> k;
    int x = n;
    for(int i = 0; i < n; i++) { 
        if(k <= caps[i].se) { x = i; break; }
    }
    cout << n - x << endl;
    return 0;
}

