#include <bits/stdc++.h>
using namespace std;

#define pb		push_back
#define eb		emplace_back
#define mk		make_pair
#define fi		first
#define se		second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;

const int N = 30;
int m[N][N];

bool isValidPosition(int r, int c) {
	return r < 10 and c < 10 and c >= 0 and r >= 0;
}

bool horizontal(int r, int c, int l, int id) {
	bool valid = true;
	for(int i = 0; i < l; i++) {
		if(!isValidPosition(r, c+i)) {
			valid = false;
			break;
		}
		int &t = m[r][c+i];
		if(t != -1) valid = false;
		t = id;
	}
	return valid;
}

bool vertical(int r, int c, int l, int id) {
	bool valid = true;
	for(int i = 0; i < l; i++) {
		if(!isValidPosition(r+i, c)) {
			valid = false;
			break;
		}
		int &t = m[r+i][c];
		if(t != -1) valid = false;
		t = id;
	}
	return valid;
}

int main() {
    ios_base::sync_with_stdio(false);

	memset(m, -1, sizeof(m));

	int n; cin >>n;
	bool valid = true;
	for(int i = 0; i < n; i++) {
		int d, l, r, c;
		cin >>d >>l >> r >>c;
		r--; c--;
		if(d == 0) valid &= horizontal(r, c, l, i);
		else valid &= vertical(r, c, l, i);
	}

	cout <<(valid ? "Y" : "N") <<endl;

    return 0;
}
