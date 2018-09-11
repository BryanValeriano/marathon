#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int T = 1e3;
int pi[T];
string p;
string t;

void phi() {
	p += '#';
	int m = p.length();
	pi[0] = pi[1] = 0;

	for(int i = 2; i <= m; i++) {
		pi[i] = pi[i-1];
		while(pi[i] > 0 and p[pi[i]] != p[i-1]) // i - 1 p/ index 1
			pi[i] = pi[pi[i]];
		if(p[pi[i]] == p[i-1]) // i - 1 p/ index 1
			pi[i]++;
	}
}

void report(int at) {
	cout << "achado em " << at << endl;
}

void kmp() {
	phi();
	int k = 0;
	int m = p.length() - 1;
	for(int i = 0; i < t.size(); i++) {
		cout << "k: " << k << " p[k]: " << p[k] << " i: " << i << " t[i]: " << t[i] << endl;
		while(k > 0 and p[k] != t[i])
			k = pi[k];
		if(p[k] == t[i]) 
			k++;
		if(k == m)
			report(i - (m - 2));
	}
}


int main() {
    ios::sync_with_stdio(false);
	cin >> p >> t;
	kmp();
	cout << "i:     ";
	for(int i = 0; i < p.length(); i++) 
		cout << setw(4) << i;
	cout << endl << "s[i]:  ";
	for(int i = 0; i < p.length(); i++) 
		cout << setw(4) << p[i];
	cout << endl << "pi[i]: ";
	for(int i = 0; i <= p.length(); i++)
		cout << setw(4) << pi[i];
	cout << endl << "i:     ";	
	for(int i = 0; i < t.length(); i++)
		cout << setw(4) << i;
	cout << endl << "t[i]:  ";
	for(int i = 0; i < t.length(); i++)
		cout << setw(4) << t[i];
			
	cout << endl;
    return 0;
}

