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

set<ll> v;

int main() {
    ios::sync_with_stdio(false);
    ll a,b;
    cin >> a >> b;

    for(ll i = 1; i*i <= a; i++) 
        if(a%i == 0) v.insert(i), v.insert(a/i);
    
    for(auto x : v) 
        if(x % b == 0) cout << x << " ";

    return 0;
}

