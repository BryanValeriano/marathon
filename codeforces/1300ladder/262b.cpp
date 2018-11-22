#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
vector<int> ans;
vector<int> pos;
vector<int> neg;

 
int main(){
	ios_base::sync_with_stdio(false);
	int n, k; cin >> n >> k;
	int aux;
	ll sum = 0;
	for(int i = 0; i < n; i++) {
		cin >> aux;
		if(aux < 0) neg.pb(abs(aux));
		else pos.pb(aux);
		sum += aux;
	}
	int totn = neg.size();
	int rest = 0;
	if(totn < k) rest += (k - totn);
	sort(neg.begin(), neg.end(), greater<int>());
	sort(pos.begin(), pos.end());
	for(int i = 0; i < min(totn, k); i++) 
		sum += 2*neg[i];
	int mini = 0;
	if(rest % 2 != 0 && pos.size() != 0) {
		mini = INF;
		if(pos.size() != 0) mini = min(mini, pos[0]);
		if(neg.size() != 0) mini = min(mini, neg[neg.size() - 1]);
	}
	else if(rest % 2 != 0 && pos.size() == 0) 
		mini = neg[neg.size() - 1];
	cout << sum - 2*mini << endl;
	
	return 0;
}
