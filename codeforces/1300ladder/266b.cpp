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
	int n, k; cin >> n >> k;
	string s; cin >> s;
	while(k--) 
		for(int i = 0; i < n-1; i++) 	
			if(s[i] == 'B' and s[i+1] == 'G') {
				swap(s[i], s[i+1]);
				i++;
			}
	cout << s << endl;
    return 0;
}

