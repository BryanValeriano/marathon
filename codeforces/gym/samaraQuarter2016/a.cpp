#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define cc(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
 
int main() {
    ios_base::sync_with_stdio(false);

    int n;
	cin >>n;
	
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int x; cin >>x;
		ans = max(x, ans);
	}
    
	cout <<ans <<endl;
    return 0;
}

