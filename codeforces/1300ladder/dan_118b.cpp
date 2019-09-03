#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;

int n;

void spaces(int n) {
	for (int i = 0; i < n; i++) {
		cout << "  ";
	}	
}

void writeLine (int toWrite, int total) {
	int spc = total - (2 * toWrite + 1);
	
	spaces(spc /2);
	
	for (int i = 0; i < 2 * toWrite + 1; i++) {
		cout << (i <= toWrite ? i : 2*toWrite-i);
		if (i < 2 * toWrite) cout << ' ';
	}
}

int main() {
    ios::sync_with_stdio(false);
	
	cin >> n;
	
	for (int i = 0; i <= 2*n; i++) {
		writeLine((i <= n ? i : 2*n-i), 2 * n + 1);
		cout << endl;
	}

    return 0;
}
