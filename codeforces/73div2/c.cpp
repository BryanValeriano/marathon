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
    ll a, b;
    cin >> a >> b;
    ll lim = (a*b)/__gcd(a,b);
    ll x = lim/a;
    ll y = lim/b;

    if(a > b) y--;
    else x--;

    if(x > y) cout << "Dasha"; 
    else if(x < y) cout << "Masha";
    else cout << "Equal";
    cout << endl;

    return 0;
}

