#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

ll fish[7] = {3,2,1,1,1,0,0};
ll rabbit[7] = {2,2,2,1,1,1,1};
ll meet[7] = {2,2,2,2,1,1,0};

ll peixe[7] = {1,1,0,0,1,0,0};
ll coelho[7] = {0,0,1,0,0,0,1};
ll carne[7] = {0,0,0,1,0,1,0};

int main() {
    ios_base::sync_with_stdio(false);

	ll f,r,m; cin >> f >> r >> m;
	ll ans = 0;

	for(int i = 0; i < 7; i++) {
		ll ff = f - fish[i];
		ll rr = r - rabbit[i];
		ll mm = m - meet[i];

		ll tent = 0;
		int ini = i;
		
		if(ff >= 0 and rr >= 0 and mm >= 0) {
			tent += 7LL-i;
			ll vezes = min({ff/3LL, rr/2LL, mm/2LL});
			tent += vezes*7LL;
			ff -= 3LL*vezes;
			rr -= 2LL*vezes;
			mm -= 2LL*vezes;
			ini = 0;
		} else  ff = f, rr = r, mm = m;

		for(int j = ini; j < 7; j++) {
			if(peixe[j]) ff--;
			if(coelho[j]) rr--;
			if(carne[j]) mm--;
			if(rr < 0 or ff < 0 or mm < 0) break;
			tent++;
		}
		ans = max(ans,tent);
	}

	cout << ans << endl;
    
    
    return 0;
}
