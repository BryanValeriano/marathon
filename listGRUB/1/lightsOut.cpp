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
    int a,b,c,d,e,f,g,h,i;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i;
    cout << (!(a+b+d)&1) << (!(a+b+c+e)&1) << (!((b+c+e)&1)) << endl;
    cout << (!(a+d+g+e)&1) << (!(d+e+f+b+h)&1) << (!(c+f+i+e)&1) << endl;
    cout << (!(g+h+d)&1) << (!(g+h+i+e)&1) << (!(i+h+f)&1) << endl;
    return 0;
}

