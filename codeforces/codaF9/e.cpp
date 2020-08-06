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
    string a,b; cin >> a >> b;
    if(a.size() != b.size()) {
        cout << "NO" << endl;
        return 0;
    }

    for(int i = 1; i < a.size(); i++) {
        char p = '0' + (a[i-1]-'0')^(a[i]-'0');
        char q = '0' + (a[i-1]-'0')|(a[i]-'0');

        if(i != a.size()-1) {
            if(b[i-1] == p) {
                a[i-1] = p, a[i] = q;
            }
            else if(b[i-1] == q) {
                a[i-1] = q, a[i] = p;
            } else {
                cout << "NO" << endl;
                return 0;
            }
        } else {
            if(b[i-1] == p and b[i] == q) {
                a[i-1] = p, a[i] = q;
            }
            else if(b[i-1] == q and b[i] == p) {
                a[i-1] = q, a[i] = p;
            } else {
                cout << "NO" << endl;
                return 0;
            }
        }

    }

    cout << "YES" << endl;

    return 0;
}

