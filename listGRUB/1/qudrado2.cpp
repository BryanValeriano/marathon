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
    if(n/2 == 0 and (n/2 & 1 == false)) { cout << "YES" << endl; return 0; }
    if(n != 1 and (n-1)/2 == 0 and ((n-1) & 1 == false)) { cout << "YES" << endl; return 0; }
    cout << "NO" << endl;

    return 0;
}

