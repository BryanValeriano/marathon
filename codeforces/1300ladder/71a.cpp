#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
	int n; cin >> n;
	while(n--) {
		string s; cin >> s;
		if(s.length() > 10) 
			cout << s[0] << s.length()-2 << s[s.length()-1];
		else cout << s;
		cout << endl;
	}

    retur 0;
}


