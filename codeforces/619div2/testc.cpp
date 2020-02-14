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
    int n,m;
    int res = 0;
    cin >> n >> m;
    string s,best;
    for(int i = 0; i < n; i++) s = (i < m? '1' : '0') + s;

    do {
        int ans = 0;

        for(int i = 0; i < s.size(); i++) {
            bool f = 0;
            for(int j = i; j < s.size(); j++) {
                f |= (s[j] == '1');
                ans += f;
            }
        }

        if(ans > res) best = s;
        res = max(ans,res);

    }while(next_permutation(s.begin(), s.end()));

    cout << res << " " << best << endl;
    return 0;
}

