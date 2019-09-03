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
    ll n,a,b;
    
    cin >> n;
    while(n) {
        cin >> a >> b;
        map<ll,int> bag;
        ll x = 0;
        ll i = 0;

        while(!bag.count(x)) {
            bag[x] = i;
            x = (((((x*x) % n) * a) % n) + b) % n;
            i++;
        }

        cout << bag[x]+(n-i) << endl; 
        cin >> n;
    }
    return 0;
}

