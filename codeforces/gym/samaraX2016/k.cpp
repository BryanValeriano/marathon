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
set<char> dict;
 
int main() {
    ios_base::sync_with_stdio(false);
	string s; cin >> s;
	for(int i = 0; i < s.size(); i++) dict.insert(s[i]);
	int ini = 0;
	int fim = s.size()-1;
	int tira;
	bool flag = false;
	bool um = true;
	bool dois = false;
	while(ini <= fim) {
		if(s[ini] == s[fim]) ini++, fim--;
		else {
			if(flag) { um = false; break; }
			if(fim-1 >= ini and s[ini] == s[fim-1]) {
				flag = true;
				tira = fim;
				fim -= 2;
				ini++;
			} 
			else { um = false; break; }
		}
	}
	ini = 0; fim = s.size()-1;
	if(um == false) {
		flag = false;
		dois = true;
		while(ini <= fim) {
			if(s[ini] == s[fim]) ini++, fim--;
			else {
				if(flag) { dois = false; break; }
				if(ini+1 <= fim and s[ini+1] == s[fim]) {
					flag = true;
					tira = ini;
					ini += 2;
					fim--;
				}
				else { dois = false; break; }
			}
		}
	}

			
	if(!flag and (um == true or dois == true)) { 
		tira = s.size()/2;
		cout << "YES" << endl;
		cout << tira+1 << endl;
	} else if(um == true or dois == true) {
		cout << "YES" << endl;
		cout << tira+1 << endl;
	} else cout << "NO" << endl;
    return 0;
}

