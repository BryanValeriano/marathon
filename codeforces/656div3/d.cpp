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
string s;

int solve(int l, int r, char c) {
	int left = 0, right = 0;
	int mid = (l+r)>>1;
	for(int i = l; i <= r; i++) {
		if(i <= mid) left += (s[i] != c);
		else right += (s[i] != c);
	}
	if(l == r) return left+right;
	return min(solve(l, mid, c + 1) + right, left + solve(mid+1, r, c+1));
}

int main() {
    ios_base::sync_with_stdio(false);
	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		cin >> s;
		cout << solve(0,n-1,'a') << endl;
	}
    return 0;
}

