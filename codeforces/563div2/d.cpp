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
 
int n,x;
 
void build(int qtd, int elim) {
	vector<int> start;	
	vector<int> tmp;
	for(int i = 0; i <= qtd; i++) {
		tmp = start;
		start.pb(pow(2,i));
		for(int j = 0; j < tmp.size(); j++) start.pb(tmp[j]);
	}
	int k = pow(2,n-1);
	for(int i = 0; i < start.size(); i++) if(start[i] & (1 << elim)) start[i] = k;
	cout << start.size() << endl;
	for(int i = 0; i < start.size(); i++) cout << start[i] << " ";
	if(start.size()) cout << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
	cin >> n >> x;
	int k = pow(2,n);
 
	if(x >= k) build(n-1,20);
	else {
		int b = 0;
		for(int i = 0; i < 18; i++) {
			if(x & (1 << i)) { 
				b = i;
				break;
			}
		}
		build(n-2,b);
	}
 
    return 0;
}
