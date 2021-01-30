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

bool pal(string s) {
    string t = s;
    reverse(t.begin(),t.end());
    return t == s;
}

int main() {
    ios_base::sync_with_stdio(false);
    string s; cin >> s;
    int m = s.size();
    int n = s.size()>>1;
    cout << (pal(s) && pal(s.substr(0,n)) && pal(s.substr(n+1,m-1))?"Yes\n":"No\n");
    return 0;
}

