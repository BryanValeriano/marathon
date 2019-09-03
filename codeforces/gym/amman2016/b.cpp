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

map<char,int> qtds;
map<int,char> maxi;

const int T = 1e5 + 10;

int tent[6] = { 6,7,3,5,4,2 };
int passo[6] = {7,6,5,4,3,2};
int ans [T];

string solve(int x, int n) {
	int iter = 0;

	while(iter < n and (n-iter)*2 <= x) {
		for(int i = 0; i < 6; i++) {
			if(x - tent[i] >= (n-iter-1)*2) {
				ans[iter] = tent[i];
				x -= tent[i];
				break;
			}
		}
		iter++;
	}
	if(x) {
		for(int i = n-1; i >= 0; i--) {
			for(int j = 0; j < 6;j ++) {
				int step = passo[j] - ans[i];
				if(x - step >= 0) {
					ans[i] += step;
					x -= step;
					break;
				}
			}
		}
	}
	
	string s;
	for(int i = 0; i < n; i++) s += maxi[ max(ans[i], 2) ];
	return s;
}
 
int main() {
    ios_base::sync_with_stdio(false);
	qtds['0'] = 6;
	qtds['1'] = 2;
	qtds['2'] = 5;
	qtds['3'] = 5;
	qtds['4'] = 4;
	qtds['5'] = 5; 
	qtds['6'] = 6;
	qtds['7'] = 3;
	qtds['8'] = 7;
	qtds['9'] = 6; 

	maxi[2] = '1';
	maxi[3] = '7';
	maxi[4] = '4';
	maxi[5] = '5';
	maxi[6] = '9';
	maxi[7] = '8';

	int tc; cin >> tc;
	while(tc--) {
		int n; string s; 
		cin >> n >> s;
		int x = 0;
		for(int i = 0; i < s.size(); i++) x += qtds[s[i]];
		s = solve(x,n);
		cout << s << endl;
	}

    return 0;
}

