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
	int impar = 0;
	int par = 0;
	int b,n,x; cin >> b >> n;
	for(int i = 0; i < n; i++) {
		cin >> x;
		if(i == n-1) {
			par += !(x&1);
			impar += (x&1);
		} else {
			if(!(b&1)) par++;
			else if((b&1)) {
				par += !(x&1);
				impar += (x&1);
			}
		}
	}
	cout << (impar&1? "odd" :  "even") << endl;

    
    
    return 0;
}
