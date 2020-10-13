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
const int T = 3e5+5;
int l[T], r[T];
multiset<int> L,R;

void ins(int i) {
    L.insert(l[i]);
    R.insert(r[i]);
}

void rem(int i) {
    L.erase(L.find(l[i]));
    R.erase(R.find(r[i]));
}

int inter() {
    int ll = *L.rbegin();
    int rr = *R.begin();
    return (rr-ll);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        ins(i);
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        rem(i);
        ans = max(ans, inter());
        ins(i);
    }
    cout << ans << endl;
    return 0;
}

