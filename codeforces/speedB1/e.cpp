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
    ll a,b;
    cin >> a >> b;
    if(a < b) swap(a,b); 
    int ans = 0;

    while(a != b and (a and b)) {
        int x = a%b;
        a = b;
        b = x;
        ans++;
    }

    cout << ans+1 << endl;

    return 0;
}

