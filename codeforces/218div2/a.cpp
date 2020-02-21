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

const int T = 102;
int aux[T];
int n,k;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    int ans = 0;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        aux[i%k] += x-1;
    }

    for(int i = 0; i < k; i++) ans += min(aux[i],n/k - aux[i]);

    cout << ans << endl; 
    
    return 0;
}

