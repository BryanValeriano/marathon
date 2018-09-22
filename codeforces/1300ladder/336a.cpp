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
	pair<int,int>um;
	pair<int,int>dois;
	int x, y;
	cin >> x >> y;
	if(x > 0) {
		um.fi = 0;
		dois.fi = abs(x) + abs(y);
		dois.sec = 0;
	} else {
		um.fi = - (abs(x) + abs(y));
		dois.fi = 0;
		um.sec = 0;
	}
	if(y < 0) 
		y = - (abs(x) + abs(y));
	else
		y = abs(x) + abs(y);
	if(um.fi == 0) 
		um.sec = y; 
	else
		dois.sec = y;
	
	cout << um.fi << " " << um.sec << " " << dois.fi << " " << dois.sec << endl;	
    return 0;
}

