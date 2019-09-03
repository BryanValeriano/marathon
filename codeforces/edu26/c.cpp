#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 110;

int a,b;
int n;
int v1[T];
int v2[T];

int solve(int x1, int y1, int x2, int y2) {
	int k = x1*y1 + x2*y2;
	if(x1 + x2 <= a and max(y1,y2) <= b) return k;
	if(x1 + x2 <= b and max(y1,y2) <= a) return k;
	if(x1 + y2 <= a and max(y1,x2) <= b) return k;
	if(x1 + y2 <= b and max(y1,x2) <= a) return k;
	if(y1 + y2 <= a and max(x1,x2) <= b) return k;
	if(y1 + y2 <= b and max(x1,x2) <= a) return k;
	if(y1 + x2 <= a and max(x1,y2) <= b) return k;
	if(y1 + x2 <= b and max(x1,y2) <= a) return k;
	return 0;
}

 
int main() {
    ios_base::sync_with_stdio(false);
	cin >> n >> a >> b;

	for(int i = 0; i < n; i++) cin >> v1[i] >> v2[i]; 

	int ans = 0;

	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++) 
			ans = max(ans, solve(v1[i],v2[i],v1[j],v2[j]));
		

	cout << ans << endl;
    
    return 0;
}
