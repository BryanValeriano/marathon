#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define cc(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;

const int N = 1e6;
vector<int> p, ast;

bool check(int mid) {
	int esq = -1;
	int last = ast[ast.size()-1];

	for(int at:p) {
		esq = *(upper_bound(ast.begin(), ast.end(), esq));
		if(at-esq > mid) return false;
		int x = (mid-(at-esq)*2, (mid-(at-esq))/2);

		int next;
		if(esq < at) next = at + x;
		else next = at+mid;
		esq = next;
		if(next >= last) return true;
	}
	
	if(esq < last) return false;
	return true;
}

int search(int ini, int fim) {
	while(ini <= fim) {
		int mid = (ini+fim)>>1;
		if(check(mid)) fim = mid-1;
		else ini = mid+1;
	}
	return ini;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n;
	cin >>n;
	
	string s; cin >>s;
	for(int i = 0; i < n; i++) {
		if(s[i] == 'P') p.pb(i);
		if(s[i] == '*') ast.pb(i);
	}
	
	cout <<search(1, N) <<endl;
    
    return 0;
}
