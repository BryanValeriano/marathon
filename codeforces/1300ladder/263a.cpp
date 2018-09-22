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
	pair<int,int>resp;
	int aux;
	for(int i = 1; i <= 5; i++) {
		for(int j = 1; j <= 5; j++) {
			cin >> aux;
			if(aux == 1) resp = mk(i,j);
		}
	}
	cout << abs(3 - resp.fi) + abs(3 - resp.sec) << endl;

    return 0;
}

