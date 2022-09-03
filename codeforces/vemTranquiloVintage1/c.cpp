#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
    ios_base::sync_with_stdio(false);
	int n; cin>>n; 
	vector<int> v;
	for(int i=0;i<n-1;i++){ 	
		int x; cin >> x;
		v.pb(x);
	}
	sort(v.begin(), v.end());
	for(int i = 1; i <= n-1; i++) {
		if(i != v[i-1]) {
			cout << i << endl;
			return 0;
		}
	}
	cout << n << endl;
    return 0;
}

