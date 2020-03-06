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

bool ok(const string &t) {
    string a,b;
    for(int i = 0; i < t.size(); i++) {
        a = t[i], b = t[i];
        for(int j = i+1; j < t.size(); j++) {
            a += t[j];
            b = t[j]+b;
            if(a == b) return 0;
        }
    }
    return 1;
}


int main() {
    ios_base::sync_with_stdio(false);
    int n,k; cin >> n >> k;
    string s; cin >> s;
    string t = s;
    char end = (char)('a'+k-1);
    char tmp = 'a';

    for(int i = s.size()-1; i >= 0; i--) {
        for(char j = s[i]+1; j <= end; j++) {
            t[i] = j;
            if(ok(t)) { cout << t << endl; return 0; }
        }
        if(tmp > 'z') break;
        t[i] = tmp;
        tmp++;
    }

    cout << "NO" << endl;

    return 0;
}

