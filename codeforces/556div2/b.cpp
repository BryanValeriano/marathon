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

const int T = 55;
char mat[T][T];
int n;

int mov[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

bool isIn(int i, int j) {
	return (i >= 0 and i < n and j >= 0 and j < n);
}
 
int main() {
    ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> mat[i][j];
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(mat[i][j] == '.') {
				int c = 0;
				for(int k = 0; k < 4; k++) {
					int ii = mov[k][0] + i;
					int jj = mov[k][1] + j;
					if(isIn(ii,jj) and mat[ii][jj] == '.') c++;
				}
				if(c == 4) {
					mat[i][j] = '#';
					for(int k = 0; k < 4; k++) {
						int ii = mov[k][0] + i;
						int jj = mov[k][1] + j;
						mat[ii][jj] = '#';
					}
			}
		}

    
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < n; j++)  
			if(mat[i][j] == '.') { cout << "NO" << endl; return 0; }
    
	cout << "YES" << endl;
    return 0;
}
