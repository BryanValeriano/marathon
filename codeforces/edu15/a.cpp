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
const double PI = acos(-1.0);
 
int main(){
    ios_base::sync_with_stdio(false);
	int best = 0, tmp = 1;
	int n,x;
	cin >> n;
	int last = INF;
	for(int i = 0; i < n; i++) {
		best = max(best,tmp);
		cin >> x;
		if(x > last) tmp++;
		else tmp = 1;
		last = x;
	}
	best = max(best,tmp);

	cout << best << endl;
    
    return 0;
}
