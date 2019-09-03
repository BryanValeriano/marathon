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
	int n, m;
	cin >> n >> m;
	string a, t;
	cin >> a >> t;
	string s1, s2;
	int i = 0;
	while(a[i] != '*' && i < n) {
		s1 += a[i];
		i++;
	}
	i++;
	while(i < n) {
		s2 += a[i];
		i++;
	}	
	int sinal = 0;
	for(i = 0; i < s1.size(); i++)
		if(s1[i] != t[i]) sinal = 1;
	if(sinal) cout << "NO";
	else {
		t.erase(t.begin()+i-1);
		int k = t.size() - 1;
		int j;
		for(j = s2.size() - 1; j >= 0 && k >= 0; j--) {
			if(s2[j] != t[k]) sinal = 1; 
			k--;
		}
		if(sinal || j != -1) cout << "NO"; 
		else cout << "YES";
	}
	cout << endl;
    return 0;
}

