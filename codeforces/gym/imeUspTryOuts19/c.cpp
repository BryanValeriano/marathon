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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

multiset<int> bag;
map<int,int> id;
int n,q;

int build(int sz) {
    auto at = bag.find(sz);
    auto it = bag.begin();
    auto tmp = bag.begin();

    ll tot = 0;
    int ans = 1;

    while(it != bag.end() and it != at) {
        if(tot + (*it) > sz) break;

        tot += *it;
        tmp = it;
        tmp++;

        it = bag.lower_bound(tot);
        if(*tmp >= *it) it = tmp;

        ans++;
    }

    tot += sz;

    it = bag.lower_bound(tot);
    if(it == at) it++;

    while(it != bag.end()) {
        tot += *it;
        it = bag.lower_bound(tot);
        ans++;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> q;
    int a,b;
    char op;

    for(int i = 1; i <= n; i++) {
        cin >> a;
        bag.insert(a);
        id[i] = a;
    }

    while(q--) {
        cin >> op >> a;
        if(op == '+') cin >> b, bag.insert(a), id[b] = a;
        else if(op == '-') bag.erase(bag.find(id[a]));
        else cout << build(id[a]) << endl;
    }

    return 0;
}

