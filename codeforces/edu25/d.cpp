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

int l[26];
vector<int> pos;
 
int main() {
    ios_base::sync_with_stdio(false);
	string p,t;
	cin >> p >> t;
	int can = 0;

	for(int i = 0; i < p.size(); i++) {
		if(p[i] == '?') can++, pos.pb(i);
		else l[p[i]-'a']++;
	}

	int i = 0;

	while(can) { 
		if(l[t[i]-'a']) l[t[i]-'a']--; 
		else can--, p[pos[can]] = t[i];
		i++;
		if(i == t.size()) i = 0;
	}
	cout << p << endl;
    return 0;
}
