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
    vector<string> v1;
    vector<string> v2;
    char tmp;
    int n; cin >> n;
    bool ok = 0;

    for(int i = 0; i < n; i++) {
        string s1,s2;
        for(int j = 0; j <  5; j++) {
            cin >> tmp;
            if(j < 2) s1 += tmp;
            else if(j > 2) s2 += tmp;
        }

        if(ok) v1.pb(s1), v2.pb(s2);
        else {
            if(s1 == "OO") s1 = "++", ok = 1;
            else if(s2 == "OO") s2 = "++", ok = 1;
            v1.pb(s1), v2.pb(s2);
        }
    }

    if(ok) {
        cout << "YES" << endl;
        for(int i = 0; i < n; i++) cout << v1[i] << "|" << v2[i] << endl;
    }

    else cout << "NO" << endl;



    return 0;
}

