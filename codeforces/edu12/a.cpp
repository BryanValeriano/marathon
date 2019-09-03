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
	int a,ta,b,tb;
	int tmp1, tmp2;
	int simmon;
	char xx;

	cin >> a >> ta >> b >> tb;
	cin >> tmp1 >> xx >> tmp2;

	simmon = (tmp1*60) + tmp2;
	int finish = simmon + ta;
	finish = min(finish, (24*60));

	int start = 5*60;
	int ans = 0;

	while(start < finish) {
		if(start + tb > simmon) ans++;
		start += b;
	}

	cout << ans << endl;
    return 0;
}
