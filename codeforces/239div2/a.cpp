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
const ll INF = 0x3f3f3f3f3f3f;

const int T = 110;
ll ans[T];
int qtd[T];
 
int main() {
    ios_base::sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> qtd[i];
		ans[i] = (qtd[i]) * 15;
	}
	int tmp;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < qtd[i]; j++) {
			cin >> tmp;
			ans[i] += 5*tmp;
		}
	}

	ll mini = INF;
	for(int i = 0; i < n; i++) mini = min(mini, ans[i]);

	cout << mini << endl;
    
    return 0;
}
