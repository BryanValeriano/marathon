#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;

bool check(ll num) {
	int sum = 0;
	while(num != 0) {
		sum += num % 10;
		num /= 10;
	}
	if(sum == 10) return true;
	else return false;
}

int main() {
    ios::sync_with_stdio(false);
	int num; cin >> num;
	int cont = 0;
	ll i;
	for(i = 0; i < INF && cont < num; i++) 
		if(check(i)) cont++;
	cout << i-1 << endl;
    return 0;
}

