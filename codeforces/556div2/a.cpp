#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main() {
    ios_base::sync_with_stdio(false);
	int n, m, r;
	cin >> n >> m >> r;
	int a,b,tmp;
	a = INF;
	b = 0;
	for(int i = 0; i < n; i++) cin >> tmp, a = min(a,tmp);
	for(int i = 0; i < m; i++) cin >> tmp, b = max(b,tmp);
	int ac = r/a;
	int rest = r % a;
	cout << max(ac*b + rest, r) << endl;
    
    
    return 0;
}
