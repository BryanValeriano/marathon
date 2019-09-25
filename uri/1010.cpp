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
    ll p1,q1,p2,q2;
    double r1,r2;
    cin >> p1 >> q1 >> r1;
    cin >> p2 >> q2 >> r2;
    cout << fixed << setprecision(2) <<"VALOR A PAGAR: R$ " << (q1*r1+q2*r2) << endl;
    return 0;
}

