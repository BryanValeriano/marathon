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

int solve(string s) {
	int x = 0;
	for(int i = 0; i < s.size(); i++) x += (s[i] >= 'A' and s[i] <= 'Z');
	return x;
}
 
int main() {
    ios_base::sync_with_stdio(false);
	string s;
	int n; cin >> s;
	
	int ans = 0;
	while(cin >> s) 
		ans = max(solve(s), ans);
	cout << ans << endl;
    
    
    return 0;
}
