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
    double a,b,c,d,e;
    cin >> a >> b >> c  >> d >> e;
    cout << fixed << setprecision(1) << (a+b+c+d+e) - max({a,b,c,d,e}) - min({a,b,c,d,e}) << endl;

    return 0;
}

