#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second

typedef pair<int,int> pii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
 
int main(){
    ios_base::sync_with_stdio(false);
	int q,x,y; cin >> q;
	while(q--) {
		cin >> x;
		y = 0;
		for(int i = 0; i < 30; i++)  {
			if((1<<i) >= x) break;
			if(!(x & (1<<i))) y += (1<<i);
		}
		if(y == 0) {
			int ans = 1;
			for(int i = 2; i*i <= x; i++) {
				if(x % i == 0) {
					ans = x/i;
					break;
				}
			}
			cout << ans << endl;
		}
		else cout << (x^y) << endl;
	}
    return 0;
}
