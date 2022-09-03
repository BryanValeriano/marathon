#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
    ios_base::sync_with_stdio(false);
	int tc; cin >> tc;
	while(tc--) {
		int a,b,c;
		cin >> a >> b >> c;
		int qtd = (a+b+c)/9;
		int ans = (a%9) + (b%9) + (c%9); 
		cout << (ans%9 || qtd > a || qtd > b || qtd > c? "NO" : "YES") << endl;
	}
    return 0;
}

