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
    int a,b,c,x,y,z;
    cin >> a >> b >> c >> x >> y >> z;
    if(a > x or (max(0, x-a) + y) < b or ((x+y+z) - (a+b) < c)) cout << "NO" << endl;
    else cout << "YES" << endl;

    return 0;
}

