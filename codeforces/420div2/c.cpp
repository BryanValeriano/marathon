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
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    string s;
    int ans = 0;
    int top = 0;
    int need = 1;

    set<int> bag;
    stack<int> tmp;

    while(cin >> s) {
        if(s == "add") {
            cin >> top;
            bag.insert(top);
            tmp.push(top);
        } else {
            if(tmp.size()) top = tmp.top();
            else if(bag.size()) top = *bag.begin();

            if(top == need) {
                bag.erase(top);
                if(tmp.size()) tmp.pop();
            } else {
                ans++;
                bag.erase(bag.begin());
                while(tmp.size()) tmp.pop();
            }
            need++;
        }
    }

    cout << ans << endl;

    return 0;
}

