#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
 
int main() {
    ios_base::sync_with_stdio(false);
	int n; cin >> n;
	ll a = 0;
	ll b = 0;
	int tmp;
	for(int i = 0; i < n; i++) {
		cin >>  tmp;
		if(tmp >= 0) a += tmp;
		else b += tmp;
	}
	cout << a - b << endl;

    
    
    return 0;
}

