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
	set<int> id;
	int n;
	cin >> n;
	int x;
	for(int i = 0; i < n; i++) {
		cin >> x;
		if(x) id.insert(x);
	}

	cout << id.size() << endl;

    
    
    return 0;
}
