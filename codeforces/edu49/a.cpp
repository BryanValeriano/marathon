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
	int tc; cin >> tc;
	while(tc--) {
		int tam; cin >> tam;
		string pal; cin >> pal;
		int meio = tam/2;
		int j = tam - 1;
		int sinal = 1;
		for(int i = 0; i < meio; i++) {
			int dist = abs(pal[i] - pal[j]);
			//cout << pal[i] << " " << pal[j] << dist << endl;
			if(dist == 1 || dist > 2 ) {
				cout << "NO" << endl;
				sinal = 0;
				break;
			}
			j--;
		}
		if(sinal) cout << "YES" << endl;
	}

    return 0;
}

