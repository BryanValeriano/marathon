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
    int n,a,x,b,y;

    cin >> n >> a >> x >> b >> y;

    while(a != x and b != y) {
        if(a == b) { cout << "YES" << endl; return 0; }
        a++;
        b--;
        if(a > n) a = 1;
        if(b < 1) b = n;
    }
    if(a == b) { cout << "YES" << endl; return 0; }
    cout << "NO" << endl;
    return 0;
}

