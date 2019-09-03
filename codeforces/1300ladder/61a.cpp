#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
#define bit CHAR_BIT;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
	string s1; cin >> s1;
	string s2; cin >> s2;
	for(int i = 0; i < s1.length(); i++) {
		if(s1[i] == s2[i]) cout << 0;
		else cout << 1;
	}
	cout << endl;
    return 0;
}

