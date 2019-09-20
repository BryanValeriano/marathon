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

int main() {
    ios_base::sync_with_stdio(false);
    int q; cin >> q;
    while(q--) {
        int n; cin >> n;
        bag.clear();

        for(int i = 0; i < n; i++) {
            int x; cin >> x; bag.insert(x);
        }

        bool flag = 1;

        while(bag.size() > 1) {
            auto ok = bag.begin();
            auto ok2 = bag.begin();
            ok2++;

            //cout << *ok << " " << *ok2 << endl;

            if(*ok == 2048 or *ok2 == 2048) {
                cout << "YES" << endl;
                flag = 0;
                break;
            }

            if(*ok2 > 2048) break;

            bag.erase(bag.find(*ok));
            if(*ok == *ok2) {
                bag.erase(bag.find(*ok2));
                bag.insert((*ok)+(*ok2));
            }
        }

        if(flag) cout << (*bag.begin() != 2048? "NO" : "YES") << endl;

    }
    return 0;
}

