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
    ll h,m,a;
    char tmp;
    cin >> h >> tmp >> m >> a;
    m += a;
    h += m/60;
    h %= 24;
    m %= 60;
    if(h < 10) cout << "0";
    cout << h  << tmp;
    if(m < 10) cout << "0";
    cout << m << endl;
    return 0;
}

