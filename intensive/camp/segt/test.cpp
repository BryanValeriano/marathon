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
	int v[3] = {1,49,100};
	cout << *(lower_bound(v, v+3, 50)) << endl;
	cout << *(upper_bound(v, v+3, 50)) << endl;
    return 0;
}

