#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
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

int main() {
    ios_base::sync_with_stdio(false);
    string t,s;
    cin >> t >> s;
    bool ok = (s.size()-1 == t.size());
    for(int i = 0; i < t.size(); i++) ok &= (s[i]==t[i]);
    cout << (ok?"Yes":"No") << endl;
    return 0;
}

