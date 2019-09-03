#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define cc(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;

const int T = 5e5 + 5;
int v[T];
int vv[T];
string s,t;
 
int main() {
    ios_base::sync_with_stdio(false);
	cin >> s;
	t = s;

	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '(') v[i]++;
		else if(s[i] == ')') v[i]--;
		else t[i] = '(', v[i]++;
		vv[i] = v[i];
	}
	
	for(int i = 1; i < s.size(); i++) v[i] += v[i-1];
	int x = v[s.size()-1] / 2;

	for(int i = s.size(); i >= 0; i--)	
		if(s[i] == '?' and x) t[i] = ')', vv[i] = -1, x--;

	for(int i = 1; i < s.size(); i++) 
		vv[i] += vv[i-1];
	
	if(vv[s.size()-1] != 0) { cout << "Impossible" << endl; return 0; }	
	for(int i = 0; i < s.size(); i++) 
		if(vv[i] < 0) { cout << "Impossible" << endl; return 0; }	

	cout << t << endl;


    return 0;
}

