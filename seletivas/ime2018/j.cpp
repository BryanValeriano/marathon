#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
string anterior;

void bk(char flag) {
	if(flag == 'y'+1) { anterior+=flag; return; }
	anterior = anterior + flag + anterior;
	return bk(flag + 1);
}

int main() {
    ios::sync_with_stdio(false);
	anterior.reserve(sizeof 33555000*(sizeof (char)));
	anterior += "a";
	bk('b');	
	int n; cin >> n;
	ll tam = anterior.size()+1;
	
	cout << anterior[(n%tam) - 1] << endl;
    return 0;
}

