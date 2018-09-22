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
	char tmp; cin >> tmp;
	char aux;
	int ans = 0;
	for(int i = 1; i < n; i++) {
		cin >> aux;	
		if(aux == tmp) ans++;
		else tmp = aux;
	}
	cout << ans << endl;

    return 0;
}

