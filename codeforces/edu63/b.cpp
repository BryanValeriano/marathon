#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

int n;
string s;

bool has() {
	int x = 0;
	for(int i = 0; i < n; i++) 
		if(s[i] == '8') x++;
	return x > (n-11)/2;
}

bool dist() {
	int x = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == '8') x++;
		if(x > (n-11)/2 and i-x+1 <= (n-11)/2) {
			return true;
		}
	}
	return false;
}


int main() {
    ios_base::sync_with_stdio(false);
	cin >> n >> s;
	if(has() and dist()) cout << "YES" << endl;
	else cout << "NO" << endl;
    return 0;
}
