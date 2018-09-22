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
	int maxi;
	int mini;
	int n; cin >> n;
	cin >> maxi;
	mini = maxi;
	int cont = 0;
	int aux;
	for(int i = 1; i < n; i++) {
		cin >> aux;
		if(aux > maxi) {
			maxi = aux;
			cont++;
		}
		else if(aux < mini) {
			mini = aux;
			cont++;
		}
	}
	cout << cont << endl;
    return 0;
}

