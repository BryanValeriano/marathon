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
const int INF = 0x3f3f3f3f;
 
int main() {
    ios_base::sync_with_stdio(false);
	int n; cin >> n;
	int at,last;
	cin >> last >> at;
	int tmp = at-last;
	bool flag = false;
	for(int i = 2; i < n; i++) {
		last = at;
		cin >> at;
		if(at-last != tmp) flag = true;
	}
	cout << (flag? at : at + tmp) << endl;
    return 0;
}

