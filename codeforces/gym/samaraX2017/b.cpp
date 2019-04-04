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


bool test(int x,int y, string s, string t) {
	int ini = max(0, x-8);
	int zz = s.size();
	int fim = min(zz, y+8);

	char tmp = s[x];
	s[x] = s[y];
	s[y] = tmp;
	
	for(int i = ini; i < fim; i++) {
		bool flag = true;
		for(int j = i; j-i < t.size(); j++) { 
			if(j == s.size()) { flag = false; break; } 
			flag &= (s[j] == t[j-i]);
		}
		if(flag) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	string s, t;
	cin >> s;
	t = "happiness";
	int ans = 0;
	int a,b,c,d;

	for(int i = 0; i < s.size(); i++) {
		bool flag = true;
		for(int j = i; j-i < t.size(); j++) { 
			if(j == s.size()) { flag = false; break; } 
			flag &= (s[j] == t[j-i]);
		}
		if(flag) {
			ans++;
			if(ans == 1) a = i, b = i+8;
			else c = i, d = i+8;
		}
	}

	if(ans <= 2) {
		cout << "YES" << endl;
		if(ans == 0) {
			for(int i = 0; i < s.size(); i++)
				for(int j = i+1; j < s.size(); j++)
					if(test(i,j,s,t)) { cout << i+1 << " " << j+1 << endl; return 0; }
		}
		else if(ans == 1) cout << a+1 << " " << a+2 << endl;
		else cout << a+4 << " " << c+2 << endl;
	} else {
		cout << "NO" << endl;
	}


	return 0;
}

