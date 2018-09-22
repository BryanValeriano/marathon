#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
vector<string>resp;

struct node {
	set<string>m;

	void expand(string &s, int i) {
		if(!m.count(s)) {
			m.insert(s);
			//cout << s << endl;
		}
	}

	bool search(string ini, string &fim, int i) {
		if(i == ini.size() && ini != fim) return false;	
		if(ini == fim) return true;	
		for(int j = 0; j < ini.size(); j++) {
			char tmp = ini[j];
			char tmp2 = fim[j];
			//cout << tmp << " " << tmp2 << endl;
			if(tmp != tmp2) {
				ini[j] = tmp2;
				if(m.count(ini)) {
					//cout << ini << " " << j << endl;
					resp.pb(ini);
					if(search(ini, fim, i + 1))
						return true;
					else {
						resp.pop_back();
						ini[j] = tmp;
					}
				}
				else ini[j] = tmp;
			}
			else ini[j] = tmp;
		}
		return false;
	}
}T;

int main() {
    ios::sync_with_stdio(false);
	int n; cin >> n;
	string ini; cin >> ini;
	for(int i = 1; i < n-1; i++) {
		string s; cin >> s;
		T.expand(s, 0);
	}
	string fim; cin >> fim;
	T.expand(fim, 0);
	resp.pb(ini);
	if(T.search(ini, fim, 0)) {
		for(auto id : resp) 
			cout << id << endl;
	}
	else	
		cout << "FAIL" << endl;
	
    return 0;
}

