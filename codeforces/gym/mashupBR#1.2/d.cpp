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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

string s;
double ans;
int dist[40];
int n;

void calc(int x) {
	int l = max(0,x-18);
	int r = min(n-1,x+18);

	for(int i = l; i <= x; i++) {
		for(int j = x; j <= r; j++) {
			int d = (j-i)+1;
			dist[d]++;
		}
	}
}

bool isVog(char x) {
	return (x == 'A' or x == 'E' or x == 'I' or x == 'O' or x == 'U' or x == 'Y');
}

int main() {
    ios_base::sync_with_stdio(false);
	cin >> s;
	n = s.size();

	for(int i = 0; i < n; i++)
		if(isVog(s[i])) calc(i);

	for(int i = 1; i < 40; i++)
		if(dist[i]) ans += 1/(double)i * (double)dist[i];

	cout << fixed << setprecision(7) << ans << endl;

    return 0;
}

