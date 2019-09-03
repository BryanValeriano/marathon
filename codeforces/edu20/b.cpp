#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 2e5 + 10;

vector<int> bag;
int v[T];
 
int main() {
    ios_base::sync_with_stdio(false);
	int n; cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> v[i];
		if(!v[i]) bag.pb(i);
	}

	for(int i = 0; i < n; i++) { 
		if(v[i]) {
			auto low = lower_bound(bag.begin(), bag.end(), i);
			if(low == bag.end()) low--;
			int l = *low;
			int r;
			if(low == bag.begin()) r = l;
			else {
				low--;
				r = *low;
			}
			cout << min(abs(r-i), abs(l-i)) << " ";
		}
		else cout << 0 << " ";
	}

	cout << endl;

    
    return 0;
}

