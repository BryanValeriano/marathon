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

map<string, int> id;

string rev(string s) {
	string t;
	for(int i = s.size()-1; i >= 0; i--) t += s[i];
	return t;
}

string trans(ll x) {
	string ans = "";
	while(x) {
		int tmp = x%10;
		if(tmp&1) ans += '1';
		else ans += '0';
		x /= 10;
	}
	while(ans.size() < 18) ans += '0';
	return rev(ans);
}

int main() {
    ios_base::sync_with_stdio(false);
	int n;
	char oper;
	ll x;
	cin >> n;
	while(n--) {
		cin >> oper >> x;
		if(oper == '+') id[trans(x)]++;
		else if(oper == '-') id[trans(x)]--;
		else cout << id[trans(x)] << endl;
	}
    return 0;
}
