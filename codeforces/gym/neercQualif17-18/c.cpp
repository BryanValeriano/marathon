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
 
int main() {
    ios_base::sync_with_stdio(false);

    ll n, k;
	cin >>n >>k;
	
	string s = "";

	ll sum = 0;
	ll ant = 0;
	while(sum < k and s.size() < 2*n) {
		if(sum + ant <= k) {
			sum += ant;
			s += '(';
			ant++;
		} else {
			s += ')';
			ant--;
		}
	}
	
	while(ant-- > 0) s += ')';
	while(s.size() < 2*n) {
		s += "()";
	}

	cout <<(sum == k and s.size() == 2*n? s : "Impossible") <<endl;
    
    return 0;
}
