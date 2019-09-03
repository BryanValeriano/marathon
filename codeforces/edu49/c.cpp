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
	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		int tmp;
		map<int,int>ind;
		for(int i = 0; i < n; i++) {
			cin >> tmp;
			ind[tmp]++;
		}
		map<int,int>::iterator it = ind.begin();
		int flag = 0;
		int row[3];
		while(flag < 2) { 
			if(it->sec >= 4) {
				row[flag++] = it->fi;
				row[flag++] = it->fi;
			}
			else if(it->sec >= 2) 
				row[flag++] = it->fi;
			it++;
		}
		for(int i = 0; i < 2; i++)
			cout << row[i] << " " << row[i] << " ";
		cout << endl;
	}

    return 0;
}

