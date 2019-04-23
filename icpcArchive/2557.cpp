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

const int T = 105;
int v[T];
int ans[T];

void pre() {

    for(int i = 2; i <= 100; i++) 
        for(int j = i; j <= 100; j += i)
            v[j]++;

    ans[1] = 1;
    for(int i = 2; i <= 100; i++) {
        if(!(v[i]&1)) ans[i]++;
        ans[i] += ans[i-1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    pre();
    int tc, x; cin >> tc;
    while(tc--) cin >> x, cout << ans[x] << endl; 
    return 0;
}

