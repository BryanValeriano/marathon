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
	int x = 0;
	string s;
	while(n--) {
		cin >> s;
		if(s[1] == '+') x++;
		else x--;
	}
	cout << x << endl;

    return 0;
}

