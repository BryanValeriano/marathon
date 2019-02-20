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
ll n, k;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;


    ll red = (2*n)/k;
    ll green = (5*n)/k;
    ll blue = (8*n)/k;
    if(2*n % k != 0) red++;
    if(5*n % k != 0) red++;
    if(8*n % k != 0) red++;
    cout << red + green + blue << endl;

    return 0;
}

