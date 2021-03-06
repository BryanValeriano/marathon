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

string s;

void solve() {
	int x = 0;
	int i = 0;
	while(i < s.size() - 1) {
		if(s[i] == s[i+1]) x++;
		else i++;
		if(x == 1 and i+2 < s.size() and s[i] == s[i+2]) {
			if(s[i+1] != 'z') s[i+1] = s[i+1] + 1;
			else if(s[i+1] != 'a') s[i+1] = s[i+1] - 1;
			i += 2;
		} else if(x == 1) {
			int last = max(i-1, 0);
			for(char j = 'a'; j <= 'z'; j++) {
				if(j != s[i] and j != s[last]) {
					s[i] = j; break;
				}
			}
			i+= 2;
		}
		x = 0;
	}
}
 
int main() {
    ios_base::sync_with_stdio(false);
	cin >> s;
	solve();
	cout << s << endl;	 
    return 0;
}
