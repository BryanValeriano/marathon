#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
	int tc; cin >> tc;
	vector<int>row;
	while(tc--) {
		row.clear();
		string s; cin >> s;
		string s2; cin >> s2;
		size_t found = s.find(s2);
		while(found != string::npos) {
			row.pb((int)found);
			found = s.find(s2, found+1);
		}
		if(row.size()) {
			cout << row.size() << endl;
			for(auto id : row) 
				cout << id+1 << " ";
		} else { 
			cout << "Not Found";
		}
		cout << endl << endl;
	}
    return 0;
}

