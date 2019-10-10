#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 6;
int v[N];
 
int main() {
	ios_base::sync_with_stdio(false);

	int ans = 0;
	for(int i = 0; i < 3; i++) 
		cin >>v[i];
	
	for(int i = 0; i < 3; i++) {
		int a; cin >>a;
		ans += max(0, a-v[i]);
	}

	cout <<ans <<endl;

	return 0;
}
 
