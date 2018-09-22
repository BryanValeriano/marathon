#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
bool flag = false;

struct Trie {
	int cnt, word;
	map<char,Trie>m;
	
	Trie() {
		cnt = word = 0;
		m.clear();
	}

	void add(string &s, int i) {
		if(word) flag = true;
		cnt++;
		if(i == s.size()) {
			word++;
			return;
		}
		if(!m.count(s[i]))
			m[s[i]] = Trie();
		m[s[i]].add(s, i + 1);
	}
	
	void destroy() {
		cnt = word = 0;	
		m.clear();
	}
}T;

bool cmp(const string&a, const string&b) {
	return  a.size() < b.size();
}

int main() {
    ios::sync_with_stdio(false);
	int tc; cin >> tc;
	while(tc--) {
		flag = false;
		vector<string>row;
		
		int n; cin >> n;
		for(int i = 0; i < n; i++) {
			string s; cin >> s;
			row.pb(s);
		}
		sort(row.begin(), row.end(), cmp);
		for(auto id : row) {
			T.add(id, 0);
		}
		cout << (flag? "NO" : "YES") << endl;
		T.destroy();
	}
    return 0;
}

