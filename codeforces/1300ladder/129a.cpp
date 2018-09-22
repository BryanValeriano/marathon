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
	int aux;
	int sum = 0;
	int impar = 0;
	int par = 0;
	for(int i = 0; i < n; i++) {
		cin >> aux;
		sum += aux;
		if(aux&1)impar++;
		else par++;
	}
	cout << (sum&1? impar : par) << endl;
    return 0;
}

