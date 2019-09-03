#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back
#define int ll

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

int n,m;

int gcd(int x, int y) {
    if(x == 0 or y == 0) return 0;
    else {
        if(x / y > 1 or y / x > 1) return 1;
        if(x >= y) return 1 + gcd(x % y, y);
        else return 1 + gcd(x, y % x);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int mini,maxi;

    while(n or m) {
        if(n < m) mini = n, maxi = m;
        else mini = m, maxi = n;
        int x = gcd(n,m);
        if(x&1) cout << "Stan wins" << endl;
        else cout << "Ollie wins" << endl;
        cin >> n >> m;
    }

    return 0;
}

