#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int T = 1e6 + 3;
string p;
int pi[T];

void phi() {
	//p += '#';
	int m = p.length();
	pi[0] = pi[1] = 0;
	for(int i = 2; i < m; i++) {
		pi[i] = pi[i-1];
		while(pi[i] > 0 and p[pi[i]] != p[i])
			pi[i] = pi[pi[i]];
		if(p[pi[i]] == p[i])
			pi[i]++;
	}
}

int search() {
	phi();
	int n = p.length();
	int gol = pi[n-1];
	int resp = 0;
	int metade = gol/2;
	if(gol % 2 != 0) metade++;
	if(gol != 0) 
		for(int i = 0; i < n-1; i++) {
			if(pi[i] == gol) 
				return gol;
			if(gol >= n/3 && pi[i] >= metade && p[i] == p[n-1])
				resp = pi[i];
			//cout << i << " " << pi[i] << " " << p[i] << " " << p[n-1] << endl;
		}
			
	return resp;
}

int main() {
    ios::sync_with_stdio(false);
	cin >> p;
	
	int resp = search();
	//cout << "i:     ";
	//for(int i = 0; i < p.length(); i++) 
	//	cout << setw(4) << i;
	//cout << endl << "s[i]:  ";
	//for(int i = 0; i < p.length(); i++) 
	//	cout << setw(4) << p[i];
	//cout << endl << "pi[i]: ";
	//for(int i = 0; i <= p.length(); i++)
	//	cout << setw(4) << pi[i];
	
	if(resp) {
		for(int i = 0; i < resp; i++) 
			cout << p[i];
		cout << endl;
	}
	else cout << "Just a legend" << endl;

    return 0;
}

