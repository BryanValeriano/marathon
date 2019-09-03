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

const int T = 5e5 + 10;
int v[T];
map<int,int> track;
 
int main() {
    ios_base::sync_with_stdio(false);
	int n,k; cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> v[i];
	
	int r = 0;
	int l = 0;
	int rr = 0;
	int ll = 0;
	int best = 0;

	while(r < n) {
		while(r < n and track.size() <= k) track[v[r++]]++;
		if(track.size() > k) r--, track.erase(v[r]);
		if(r - l + 1 > best) {
			best = r - l + 1;
			rr = r-1;
			ll = l;
		}
		while(l < n and track.size() >= k) {
			track[v[l]]--;
			if(track[v[l]] == 0) track.erase(v[l]);
			l++;
		}
	}
	cout << ll+1 << " " <<  rr+1 << endl;
    
    
    return 0;
}


