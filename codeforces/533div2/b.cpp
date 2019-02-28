#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;
int freq[30];

int main() {
    ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	string s; cin >> s;
	

	for(int i = 0; i <= 26; i++) {
		int cont = 0;
		for(int j = 0; j < n; j++) {
			if(s[j] == 'a' + i) cont++;
			else cont = 0;
			if(cont != 0 and cont % k == 0) freq[i]++;
		}
	}

	int best = 0;
	for(int i = 0; i < 30; i++) best = max(best, freq[i]);
	cout << best << endl;
    
    return 0;
}
