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
	int resp = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			int k = (i ^ j);
			if(k <= n && k > j && k < i + j) {
				resp++;
				//cout << i << " " << j << " " << k << endl;
			}
		}
	}
	
	cout << resp << endl;

    return 0;
}

