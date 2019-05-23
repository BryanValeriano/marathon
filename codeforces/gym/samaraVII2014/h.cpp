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

string s;
string t = "desmond";

void init() {
	for(int i = 0; i < s.size(); i++) {
		int x = 0;
		for(int j = i; j < i+7 and j < s.size(); j++) {
			if(s[j] == t[j-i]) x++; 
		}
		if(x == 7) {
			cout << "I love you, Desmond!" << endl;
			cout << 0 << endl;
			exit(0);
		}
	}
}

bool check(int x) {
	int ini = max(0,x-7+1);
	int fim = min((int)s.size(), x+7);
	for(int i = ini; i < fim; i++) {
		int x = 0;
		for(int j = i; j < i+7 and j < s.size(); j++)  
			if(s[j] == t[j-i]) x++; 
		if(x == 7) return true;
	}
	return false;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin >> s;
	int m; cin >> m;
	init();
	int x; 
	char y;
	int i = 1;
	while(i <= m) {
		cin >> x >> y;	
		s[x-1] = y;
		if(check(x-1)) {
			cout << "I love you, Desmond!" << endl;
			cout << i << endl;
			return 0;
		}
		i++;
	}
	cout << "Goodbye, my love!" << endl;	
    return 0;
}



