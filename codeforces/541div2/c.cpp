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
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
const int T = 110;
int v[T];

int main() {
    ios_base::sync_with_stdio(false);
	deque<int> list;
	int n; cin >> n;
	for(int i = 0; i < n; i++) cin >> v[i];
	sort(v, v+n);
	for(int i = 0; i < n; i++) {
		if(i&1) list.push_back(v[i]);
		else list.push_front(v[i]);
	}
	for(auto x : list) cout << x << " "; 
	cout << endl;
    return 0;
}
