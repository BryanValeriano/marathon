#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

pair<int,int> primeiraAparicao(string &s, string pattern) {
	int length = pattern.length();
	for(int i = 0; i < (int)s.length(); i++) {
		int match = 0;
		for(int j = 0; j < length; j++) {
			if(i+j >= (int)s.length() || s[i+j] != pattern[j]) break;
			match++;
		}
		if(match == length) return make_pair(i, i+1);
	}
	return make_pair(-1,-1);
}

pair<int,int> ultimaAparicao(string &s, string pattern) {
	int length = pattern.length();
	for(int i = s.length()-1; i >= 0; i--) {
		int match = 0;
		for(int j = 0; j < length; j++) {
			if(i+j >= (int)s.length() || s[i+j] != pattern[j]) break;
			match++;
		}
		if(match == length) return make_pair(i,i+1);
	}
	return make_pair(-1,-1);
}

int sizeInterval(pair<int,int> interval) {
	return interval.se-interval.fi+1;
}

bool intersect(pair<int,int> x, pair<int,int> y) {
	int size = sizeInterval(x) + sizeInterval(y);
	x.fi = min(x.fi,y.fi);
	x.se = max(x.se,y.se);
	return size > sizeInterval(x);
}

int main() {
    ios_base::sync_with_stdio(false);
	string s; cin >> s;
	s = "#" + s;
	pair<int,int> primeiroAB = primeiraAparicao(s, "AB");
	pair<int,int> primeiroBA = primeiraAparicao(s, "BA");
	pair<int,int> ultimoAB = ultimaAparicao(s, "AB");
	pair<int,int> ultimoBA = ultimaAparicao(s, "BA");
	pair<int,int> joker = make_pair(-1,-1);
	bool nok = (primeiroAB == joker || primeiroBA == joker);
	if(nok || (intersect(primeiroAB, ultimoBA) && intersect(primeiroBA, ultimoAB))) cout << "NO" << endl;
	else cout << "YES" << endl;
    return 0;
}

