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
	string s; cin >> s;
	for(int i = 0; i < s.length(); i++) 
		if(s[i] == 'H' || s[i] == 'Q' || s[i] =='9') {
			cout << "YES" << endl;
			return 0;
		}
	cout << "NO" << endl;

    return 0;
}

