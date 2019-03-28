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
	string s1,s2;
	cin >> s1 >> s2;
	string t1,t2;

	while(s1.size() + t1.size() < s2.size()) t1 += "0";
	s1 = t1 + s1;
	while(s2.size() + t2.size() < s1.size()) t2 += "0";
	s2 = t2 + s2;

	if(s1 < s2) cout << "<" << endl;
	else if(s2 < s1) cout << ">" << endl; 
	else cout << "=" << endl;
    
    return 0;
}
