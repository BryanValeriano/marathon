#include <stdio.h>
#include <iostream>
#include <vector>
#include <assert.h>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <memory.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
typedef long long ll;
int main()
{
	int n;
	scanf("%d", &n);
	map<ll, int> has;
	int x;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x);
		has[x] = 1;
	}
	vector<int> res = { x };
	for (auto x : has) {
		for (ll d = 1; d <= 2e9 + 10; d *= 2) {
			ll need = x.first + d;
			if (has.find(need) != has.end()) {
				vector<int> cur;
				cur.push_back(x.first);
				if (d > 1 && has.find(x.first + d / 2) != has.end())
					cur.push_back(x.first + d / 2);
				cur.push_back(x.first + d);
				if (cur.size() > res.size())
					res = cur;
			}
		}
	}
	cout << res.size() << endl;
	for (auto x : res)
		cout << x << " ";
	return 0;
}
