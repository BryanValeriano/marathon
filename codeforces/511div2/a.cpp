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
	for(int i = 3; i < 1e9; i++) {
		n = i;
		int parcial1 = n/3;
		int parcial2 = n/3;
		int resto = n/3 + n%3;			

		while(parcial1%3 == 0 || parcial2%3 == 0 || resto%3 == 0){
			if(parcial1>1 && parcial1%3 == 0){
				resto++;
				parcial1--;
			}
			if(parcial2>1 && parcial2%3 == 0){
				resto++;
				parcial2--;
			}
			if(resto>2 && resto%3 == 0){
				resto-=2;
				parcial2+=2;
			}
		}	
		//cout << parcial1 << " " << parcial2 << " " << resto << endl;
		//cout << parcial1 + parcial2 + resto << endl;
		if(n != (parcial1 + parcial2 + resto) or (parcial1 % 3 == 0) or (parcial2 % 3 == 0)
				or (resto % 3 == 0))
				cout << "AAAAAAAAAAAAAAAAAAAAAAAAAA: " << n << endl;
				
	}
    return 0;
}

