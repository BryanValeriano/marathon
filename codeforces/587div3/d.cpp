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
const int T = 2e5 + 5;
int v[T];
 
int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int maxi = 0;
    int gcd = 0;
    ll vez = 0;

    for(int i = 0; i < n; i++) {
        cin >> v[i];
        maxi = max(maxi,v[i]);
    }



    for(int i = 0; i < n; i++) {
        if(v[i] == maxi) continue;
        gcd = __gcd(gcd, maxi - v[i]);
        vez += maxi - v[i];
    }

    cout << vez/gcd << " " << gcd << endl; 
    
    return 0;
}

