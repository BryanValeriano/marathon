#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
	int cop, ori; cin >> cop >> ori;
	int aux = 0;	
	aux = max(0, ori - 1);
	int tmp = cop - aux;
	if(tmp < 0 || (tmp != 0 && tmp % 2 != 0) || (ori <= 1  && cop > 0) || (ori == 0 && cop == 0)) 
		cout << "No" << endl;
	else cout << "Yes" << endl;

    return 0;
}

