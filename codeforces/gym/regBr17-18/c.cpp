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

const int N = 1e3 + 5;
int v[N];
 
int main() {
	ios_base::sync_with_stdio(false);

	int k, n;
	cin >>k >>n;

	for(int i = 0; i < n; i++) {
		int a;
		cin >>a;
		v[a]++;
	}

	ii menor = ii(v[1], 1);
	ii maior = ii(v[1], 1);

	for(int i = 1; i <= k; i++) {
		menor = min(menor, ii(v[i], i));
		maior = max(maior, ii(v[i], i));
	}

	bool valido;
	int check;

	check = menor.fi+1;
	valido = true;
	v[menor.se]++;
	for(int i = 1; i <= k; i++) 
		valido &= (v[i] == check);
	v[menor.se]--;

	if(valido) {
		cout <<'+' <<menor.se <<endl;
		return 0;
	}

	check = maior.fi-1;
	valido = true;
	v[maior.se]--;
	for(int i = 1; i <= k; i++) 
		valido &= (v[i] == check);
	v[maior.se]++;

	if(valido) {
		cout <<'-' <<maior.se <<endl;
		return 0;
	}

	check = maior.fi-1;
	valido = true;
	v[maior.se]--;
	v[menor.se]++;
	for(int i = 1; i <= k; i++) 
		valido &= (v[i] == check);
	if(valido) {
		cout <<'-' <<maior.se <<" +" <<menor.se <<endl;
		return 0;
	}
	
	cout <<"*" <<endl;

	return 0;
}
 
