#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

int qtd[26];
string s;

int temMenor(int x) {
	int t = s[x] - 'a';
	for(int i = t-1; i >= 0; i--) 
		if(qtd[i]) return i;
	return -1;
}

int find(int ini, int x) {
	for(int i = ini+1; i < s.size(); i++) if(s[i] - 'a' == x) return i;
}

int main() {
    ios_base::sync_with_stdio(false);
	int n;
	cin >> n >> s;
	for(int i = 0; i < n; i++) qtd[s[i]-'a']++;

	for(int i = 0; i < n; i++) {
		int x = temMenor(i);
		qtd[s[i]-'a']--;
		if(x != -1) { 
			x = find(i,x);
			cout << "YES" << endl << i+1 << " " << x+1 << endl; return 0; 
		}
	}

	cout << "NO" << endl;
    
    
    return 0;
}
