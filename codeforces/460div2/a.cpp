#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main() {
    //ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	float a;
	float b;
	float res[n];
	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		res[i] = a/b; 
	}
	sort(res, res + n);
	printf("%lf\n", m * res[0]);


    return 0;
}

