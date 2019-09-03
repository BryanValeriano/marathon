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
const ll INF = 0x3f3f3f3f3f3f;
 
int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    char oper;
    ll x;
    while(tc--) {
        int n; cin >> n;
        ll tot = 0;
        ll limiteSup = INF;
        for(int i = 0; i < n; i++) {
            cin >> x >> oper;
            if(oper == '+') tot += x + 25;
            else limiteSup = min(limiteSup, tot + x + 25);
        }
        cout << limiteSup - tot << endl;
    } 
    return 0;
}

