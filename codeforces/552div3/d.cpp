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

const int T = 2e5 + 10;
int v[T];

int main() {
    ios_base::sync_with_stdio(false);
	int n,b,a; cin >> n >> b >> a;
	int maxa = a;
	for(int i = 0; i < n; i++) cin >> v[i];

	int i;
	for(i = 0; i < n; i++) { 
		if(v[i] and a < maxa and b) b--, a++;
		else if(v[i] and a) a--;
		else if(v[i]) break;

		if(!v[i] and a) a--;
		else if(!v[i] and b) b--;
		else if(!v[i]) break;
	}

	cout << i << endl;

    return 0;
}
