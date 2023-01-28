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

void print(vector<int> &v, int qtd) {
	while(qtd && v.size()) {
		cout << v.back() << " ";
		v.pop_back();
		qtd--;
	}
}

int main() {
    ios_base::sync_with_stdio(false);
	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		if(n < 4) {
			cout << -1 << endl;
			continue;
		} else {
			vector<int> odd;
			vector<int> even;
			for(int i = 1; i <= n; i++) {
				if(i&1) odd.pb(i);
				else even.pb(i);
			};
			while(odd.size()) {
				cout << odd.back() << " ";
				odd.pop_back();
			}
			cout << "4 2 ";
			for(int i = 2;i < even.size(); i++) cout << even[i] << " ";
			cout << endl;
		}
	}
    return 0;
}

