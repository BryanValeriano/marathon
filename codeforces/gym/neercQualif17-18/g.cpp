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
const int INF = 0x3f3f3f3f;

int v[10];
 
int main() {
    ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int ans = 0;
	string s;
	for(int i = 0; i < n; i++) {
		cin >> s;
		for(int j = 0; j < s.size(); j++) if(s[j] == '1') {
			v[j]++;
			ans = max(ans, v[j]);
		}
	}

	cout << ans << endl;
    
    return 0;
}

