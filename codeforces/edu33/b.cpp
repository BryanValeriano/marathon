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

vector<ll> divv;

void gen() {
    ll x = 0;
    divv.pb(1);
    for(int i = 0; i <= 20; i++) {
        x = 0;
        for(int j = i; j <= i+i; j++) x |= (1LL<<j);
        divv.pb(x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    gen();
    reverse(divv.begin(), divv.end());
    int n;
    cin >> n;
    for(auto x : divv) 
        if(n % x == 0) { cout << x << endl; break; } 


    return 0;
}

