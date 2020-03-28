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
    string s; cin >> s;
    int bank = 0, ans = 0;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'g') {
            if(bank) ans++, bank--;
            else bank++;
        }
        if(s[i] == 'p') {
            if(bank) bank--;
            else ans--, bank++;
        }
    }

    cout << ans << endl;
    return 0;
}

