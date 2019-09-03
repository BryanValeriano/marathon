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
	int x1,x2,y1,y2;
	cin >> x1 >>y1 >>x2 >> y2;
	cout << max(abs(x1-x2), abs(y1-y2)) << endl;
    return 0;
}
