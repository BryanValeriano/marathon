#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int TAM = 22000 + 3;
set<string>row;
vector<string>query[TAM];

struct Trie {
	int word;
	int type;
	map<char,Trie>m;

	Trie() {
		word = type = 0;	
		m.clear();
	}

	void add(string &s, int t, int i) {
		if(type) {
			if(i != s.size() && !t) 
				query[type].pb(s);
			
		}
		if(i == s.size()) {
			if(word) return;
			word++;
			type = t;
			return;
		}
		if(!m.count(s[i])) 
			m[s[i]] = Trie();
		m[s[i]].add(s, t, i + 1);
	}
}T;			


int main() {
    ios::sync_with_stdio(false);
	int n; cin >> n;
	for(int i =0; i < n; i++) {
		string s; cin >> s;
		row.insert(s);
	}
	int k; cin >> k;
	for(int i = 0; i < k; i++) {
		string s; cin >> s;
		T.add(s, i+1, 0);
	}
	for(auto id : row) {
		T.add(id, 0, 0);
	}
	for(int i = 1; i <= k; i++) {
		cout << "Case #" << i << ":" << endl;
		if(query[i].size()) {
			sort(query[i].begin(), query[i].end());
			for(auto id : query[i]) 
				cout << id << endl;
		} else {
			cout << "No match." << endl;
		}
	}

    return 0;
}

