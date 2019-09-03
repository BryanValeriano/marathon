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

vector<int> ans;

bool isPrime(int x) {
    for(int i = 2; i*i <= x; i++)
        if(x % i == 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;

    for(int i = 2; i <= n; i++) {
        if(isPrime(i)) {
            ans.pb(i);
            int j = i*i;
            while(j <= n) ans.pb(j), j *= i;
        }
    }
    
    cout << ans.size() << endl;
    for(auto x : ans) cout << x << " ";
    cout << endl;

    return 0;
}

