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
const int INF = 0x3f3f3f3f;

const int T = 3e5 + 10;
int v[T];
vector<int> zeros;
 
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	int maxi = 0;
	int best = 0;
	
	for(int i = 0; i < n; i++) {
		cin >> v[i];
		if(!v[i]) zeros.pb(i);
	}

	for(int i = 1; i < n; i++) 
		if(v[i]) v[i] += v[i-1];

	for(int i = n-1; i >= 0; i--) {
		if(v[i]) {
			maxi = max(maxi, v[i]);
			best = max(best, maxi);
			v[i] = maxi;
		}
		else maxi = 0;
	}


	int ini = INF, fim = INF;
	
	int tmp = 0;

	for(int j = 0; j < zeros.size() and j < k; j++) {
		if(zeros[j]-1 >= 0) tmp += v[zeros[j]-1];
		if(j+1 == zeros.size() or j + 1 == k)
			if(zeros[j]+1 < n) tmp += v[zeros[j]+1];
		tmp++;
	}
	if(tmp > best) {
		best = tmp;
		ini = 0;
		fim = min((int)zeros.size()-1, k-1);
	}

	for(int i = k; i < zeros.size(); i++) {
		if(zeros[i-k]-1 >= 0) tmp -= v[zeros[i-k]-1];
		if(zeros[i] + 1 < n) tmp += v[zeros[i]+1];
		if(tmp > best) {
			best = tmp;
			ini = i-k+1;
			fim = i;
		}
	}

	cout << best << endl;
	for(int i = ini; i <= fim and i < zeros.size(); i++) v[zeros[i]] = 1;
	for(int i = 0; i < n; i++) cout << (v[i] >= 1) << " ";
	cout << endl;
    
    return 0;
}
