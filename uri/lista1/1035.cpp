#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
    ios_base::sync_with_stdio(false);
    ll a,b,c,d; cin >> a >> b >> c >> d;
    cout << ((b > c and d > a and c+d > a+b and c > 0 and d > 0 and a%2 == 0)? "Valores aceitos" : "Valores nao aceitos") << endl;

    return 0;
}

