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
	int n; cin >> n;
	while(n--) {
		string palavra;
		cin >> palavra;
		int sinal = 1;
		for(int i = 1; i < palavra.size(); i++) 
			if(tolower(palavra[i]) <= tolower(palavra[i-1])) { 
				sinal = 0;
				break;
			}
		cout << palavra;
		(sinal)? cout << ": O" : cout << ": N";
		cout << endl;
	}

    return 0;
}

