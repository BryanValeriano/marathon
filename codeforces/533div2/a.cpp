#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;
const int T = 1000;
int v[T];

int main() {
    ios_base::sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 0; i < n; i++) cin >> v[i];

	int t = 1;
	int best = INF;
	for(int i = 1; i <= 101; i++) {
		int ans = 0;
		for(int j = 0; j < n; j++) {
			if(abs(i - v[j]) > 1)
				ans += abs(i - v[j]) - 1;
		}
		if(ans < best) {
			best = ans;
			t = i;
		}
	}
	cout << t << " " << best << endl;
			
    
    
    return 0;
}

