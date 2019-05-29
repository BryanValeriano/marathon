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

const int N = 1e6 + 5;
const int M = 30;

int v[N][M]; 
int z[6];

int luck(int x) {

	int a = 0, b = 0;
	int i = 0;
	
	while(x) {
		if(i < 3) a += x % 10;	
		else b += x % 10;
		x /= 10;
		i++;
	}

	return abs(b-a);
}

void pre() {
	for(int i = 0; i < N; i++) {
		int l = luck(i);
		v[i][l]++;
	}

	for(int j = 0; j < M; j++)
		for(int i = 1; i < N; i++)
			v[i][j] += v[i-1][j];

	for(int i = 0; i < N; i++)
		for(int j = 1; j < M; j++)
			v[i][j] += v[i][j-1];
}

 
int main() {
	ios_base::sync_with_stdio(false);
	pre();
	int n; cin >> n;
	while(n--) {
		int x; cin >> x;
		int l = luck(x);
		if(x and l) cout << v[x-1][l-1] << endl;
		else cout << 0 << endl;
	}

	return 0;
}

