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
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 

int main() {
    ios_base::sync_with_stdio(false);
	int col = 0;
	int lin = 1;
	string s; cin >> s;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '0') {
			if(col == 1) { cout << "3 1" << endl; col = 0; }
			else { cout << "1 1" << endl; col++; }
		} else {
			cout << lin << " " << 2 << endl;
			lin++;
			if(lin == 5) lin = 1;
		}
	}
    
    return 0;
}
