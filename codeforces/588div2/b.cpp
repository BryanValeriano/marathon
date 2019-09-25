#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
int n,k;
string s;

int main() {
    ios_base::sync_with_stdio(false);
	cin >> n >> k >> s;
	if(!k) { cout << s << endl; return 0; }
	if(n == 1) { cout << 0 << endl; return 0; }
	if(s[0] > '1') s[0] = '1', k--;
	for(int i = 1; i < n and k; i++) if(s[i] > '0') s[i] = '0', k--;
	cout << s << endl;
    return 0;
}
