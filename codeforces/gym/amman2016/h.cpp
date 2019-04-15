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
 
int main() {
    ios_base::sync_with_stdio(false);
	int tc; cin >> tc;

	while(tc--) {
		int n,m; cin >> n >> m;
		m++;
		string s; cin >> s;
		int cont = 0;
		bool flag = false;
		for(int i = 0; i < s.size(); i++) {
			if(s[i] == '0') cont++;
			else {
				if(cont >= m) flag = true; 
				cont = 0;
			}
		}
		if(cont >= m) flag = true;
		cout << (flag? "yes" : "no") << endl;
	} 

    return 0;
}

