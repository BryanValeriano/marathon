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
    cin.tie(NULL); cout.tie(NULL);
    ll x;
    cin >> x;
    while(x) {
        ll y = sqrt(x);
        cout << ((y*y) == x? "yes" : "no") << endl; 
        cin >> x;
    }
    return 0;
}

