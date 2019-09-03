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

const int N = 2e5 + 5;
set<int> s[N];
int qtd[N];

int main() {
    ios_base::sync_with_stdio(false);

    int n, m;
	cin >>n >>m;
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >>a >>b;
		s[a].insert(b);
		s[b].insert(a);
		qtd[a]++;
		qtd[b]++;
	}
	
	int id = 1;
	for(int i = 1; i <= n; i++) {
		s[i].insert(i);
		if(qtd[id] > qtd[i]) id = i;
	}
    
	for(int i = 1; i <= n; i++) 
		cout <<!s[id].count(i) <<' ';
	cout <<endl;

    return 0;
}

