#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define loop(x) for(int i = 0; i < x; i++)
#define each(x, xs) for(auto &x : xs)
#define endl '\n'
#define cc(x) cout <<#x <<" = " <<x <<endl

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
	ios_base::sync_with_stdio(false);
	string s; cin >> s;
	string t = s;
	string ok = s;
	reverse(s.begin(), s.end());

	int qtd = 0;
	while(t.size() and t != s) {
		t = t.substr(1,s.size()-1);
		s.pop_back();
		qtd++;
	}

	for(int i = qtd-1; i >= 0; i--) ok += ok[i];
	cout << ok << endl;

	return 0;
}

