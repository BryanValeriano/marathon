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

const int T = 303;
int ans[T][T];
 
int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(j&1) cout << (n*(j-1) + i) << " ";
            else cout << ((n*j) - (i-1)) << " ";
        }
        cout << endl;
    }

    
    
    return 0;
}

