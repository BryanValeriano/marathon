#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main() {
    ios_base::sync_with_stdio(false);
	ll h1,w1,h2,w2;
	cin >> w1 >> h1 >> w2 >> h2;
	ll fst = (w1 * h1) + (w2 * h2);
	ll sec = ((w1 + 2) * (h1 + 2)) + ((w2+2) * (h2+2));
	sec -= 2*min((w2+2), (w1+2));
	cout << sec - fst << endl;
    return 0;
}
