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
    ll n; cin >> n;
    ll j = 0;
    ll i = 1;

    while(i <= n) j++, i = i+j; 
    if(i == n) { cout << 1 << endl; return 0; }
    i--;
    ll dif = i-n;
    j -= dif;
    cout << j << endl;
    
    return 0;
}

