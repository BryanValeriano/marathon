#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define INFLL              0x3f3f3f3f3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

#define L(x) x << 1
#define R(x) x << 1 | 1

const ll mod = 1000000007;
const int N = 30000 + 10, T = 4 * N + 10;

vi len(T, 0), cont(T, 0), cnt(N, 0);

void update(int node, int i, int j, int a, int b, int val) {
    if(i > b or j < a) return;
    if(i >= a and j <= b) cont[node] += val;
    else if(i != j) {
        int mid = (i+j) >> 1;
        update(2*node,i,mid,a,b,val);
        update(2*node+1,mid+1,j,a,b,val);
    }
    if(cont[node]) len[node] = (j-i+1);
    else if(i!=j) len[node] = len[2*node] + len[2*node+1];
    else len[node] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	vector<tuple<int, int, int, int>> sl;
	int x1, x2, y1, y2;
	loop(n) {
		cin >> x1 >> y1 >> x2 >> y2;
		sl.emplace_back(x1, y1, y2, 1);
		sl.emplace_back(x2, y1, y2, -1);
	}
	sort(iter(sl));
	int last = 0, ans = 0, x, val;
	each(t, sl) {
		tie(x, y1, y2, val) = t;
		ans += (x - last) * len[1];
		update(1, 0, N - 1, y1, y2 - 1, val);
		last = x;
	}
	cout << ans << endl;
	return 0;
}
