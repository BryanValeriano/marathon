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
		string prob; cin >> prob;
		string test; cin >> test;
		string duo, invert, invertduo, invertprob;
		duo = test + test;
		int tam = test.size() - 1;
		int tam2 = prob.size() - 1;
	
		for(int i = tam; i >= 0; i--)
			invert += test[i];

		invertduo = invert + invert;
		
		size_t found = test.find(prob);
		size_t found2 = invert.find(prob);
		size_t found3 = duo.find(prob);
		size_t found4 = invertduo.find(prob);
		if(found != string::npos ||
				found2 != string::npos ||
				found3 != string::npos || 
				found4 != string::npos  ) cout << "S";
		else cout << "N";
		cout << endl;
	}

		
		
    return 0;
}

