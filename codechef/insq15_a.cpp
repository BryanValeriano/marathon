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
const int T = 5e6+2;
const int p[2] = {31,47};
const int m[2] = {1073897359,1442968193};
ll po[2][T], ha[2][T];
string s;
int n;

void pre() {
    for(int j = 0; j < 2; j++) {
        po[j][0] = 1;
        for(int i = 1; i < n; i++) {
            po[j][i] = (po[j][i-1]*p[j])%m[j];
            ha[j][i] = (ha[j][i-1] + (s[i]-'a'+1)*po[j][i])%m[j];
        }
    }
}

bool check(int p, int k) {
    ii ok = mk((ha[0][k]*po[0][p])%m[0],
               (ha[1][k]*po[1][p])%m[1]);
    ii nok = mk((ha[0][p+k]-ha[0][p]+m[0])%m[0],
                (ha[1][p+k]-ha[1][p]+m[1])%m[1]);
    return ok==nok;
}

int bb(int p) {
    int l = 0, ans = 0;
    int r = min(p,n-p);
    while(l <= r) {
        int mid = (l+r)>>1;
        if(check(p,mid)) ans = mid, l = mid+1;
        else r = mid-1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int q,p;
    cin >> s;
    s = "#" + s;
    n = s.size();
    pre();
    cin >> q;
    while(q--) {
        cin >> p;
        cout << bb(p) << endl;
    }
    return 0;
}

