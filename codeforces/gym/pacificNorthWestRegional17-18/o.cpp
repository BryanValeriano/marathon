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
const int T = 40;

int n;
set<int> row[T], col[T];
vector<int> r, c;

int main() {
    ios_base::sync_with_stdio(false);

    while(cin >> n) {
        char x;

        r.clear(), c.clear();
        for(int i = 0; i < n; i++)
            row[i].clear(), col[i].clear();

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                cin >> x;
                row[i].insert(x);
                col[j].insert(x);
                if(i == 0) r.pb(x);
                if(j == 0) c.pb(x);
            }


        bool a = 1;
        for(int i = 0; i < n and a; i++)
            a &= (row[i].size() == col[i].size() and row[i].size() == n);

        if(!a) { cout << "No" << endl; continue; }

        bool b = 1;
        vector<int> rr = r;
        vector<int> cc = c;
        sort(rr.begin(), rr.end());
        sort(cc.begin(), cc.end());
        b &= (r == rr) and (c == cc);

        cout << (b? "Reduced" : "Not Reduced") << endl;
    }
    return 0;
}

