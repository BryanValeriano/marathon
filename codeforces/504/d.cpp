#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int tam = 2e5+3;
int a[tam];
int b[tam];

int main() {
    ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	a[0] = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] == 0) {
			for(int aux = 1; aux < m; aux++) {
				if(b[a[i-1]+aux] < 2) {
					a[i] = a[i-1]+1;
					b[a[i-1]+1]++;
					break;
				}
			}
		}
		if(a[i] < a[i-1]) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	for(int i = 1; i <= n; i++) 
		cout << a[i] << " ";
	cout << endl;
    return 0;
}

