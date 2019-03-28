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
    int h1,h2,m1,m2;
    char tmp;
    cin >> h1 >> tmp >> m1;
    cin >> h2 >> tmp >> m2;

    h1 *= 60;
    h2 *= 60;
    h1 += m1;
    h2 += m2;

    int x = (h1+h2)/2;
    int y = x%60;
    x /= 60;

    if(x >= 10) cout << x;
    else cout << '0' << x;
    cout << tmp;
    if(y >= 10) cout << y;
    else cout << '0' << y;
    cout << endl;

    return 0;
}

