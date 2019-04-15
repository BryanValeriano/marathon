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

const int T = 1e5 + 10;
int v[T];
int cool[10] = { 2,3,5,7,11,13,17,19,23,29};

void pre() {
    for(int i = 0; i < T; i++) {
        int x = __builtin_popcount(i);
        for(int j = 0; j < 10; j++) 
            if(x == cool[j]) v[i]++;
    }
    for(int i = 1; i < T; i++) v[i] += v[i-1];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    pre(); 
    while(tc--) {
        int l,r; cin >> l >> r;

        cout << v[r] - (l == 0? 0 : v[l-1]) << endl;
    } 
    return 0;
}

