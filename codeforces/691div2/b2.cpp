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
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
int mov[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

int main() {
    ios_base::sync_with_stdio(false);
	set<ii> old;
	set<ii> novo;
	old.emplace(0,0);
	for(int i = 1; i <= 10; i++) {
		novo.clear();
		for(ii v : old) {
			for(int j = 0; j < 4; j++) {
				novo.emplace(v.fi + mov[j][0], v.se + mov[j][1]);
			}
		}
		cout << i << " = " << novo.size() << endl;
		old = novo;
		novo.clear();
	}
    return 0;
}

