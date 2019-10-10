#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define cc(x) cout <<#x <<" = " <<x <<endl

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
	ios_base::sync_with_stdio(false);
	
	int n, m, k;
	cin >>n >>m >>k;

	if(k <= m) {
		double rest = m-(k-1);
		cout <<fixed <<setprecision(8) <<(1.0/k)*((k-1)+(rest/(rest+n))) <<endl;
	}
	else {
		cout <<fixed <<setprecision(8) <<((double)m/k) <<endl;
	}

	return 0;
}
 
