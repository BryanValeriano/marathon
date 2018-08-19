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
	float n, q;
	cin >> n >> q;
	int invert;
	((int)n&1)? invert = 1 : invert = 0; 
	int start1 = ceil(pow(n,2)/2.0)+1; 
	int start2 = 0;
	int linimpar = ceil(n/2.0); 
	int linpar = floor(n/2.0);
	
	while(q--) {
		float lin, col;
		cin >> lin >> col;
		int li = n/2;
		int qtd = n/2;
		int result;
		if(int(lin + col) % 2 == 0) {
			if(invert) {
				int qtdimpar = ceil(lin/2.0);
				int qtdpar = floor(lin/2.0);

				result = (linimpar*qtdimpar) + (linpar*qtdpar);
			} else {

				result = li * qtd;
			}
		} else {
			if(invert) {
				int qtdpar = ceil(lin/2.0);
				int qtdimpar = floor(lin/2.0);

				result = (linimpar*qtdimpar) + (linpar*qtdpar) + start1;
			} else {

					result = (li * qtd) + start1;	
			}
		}
		cout << result << endl;
	}
    return 0;
}

