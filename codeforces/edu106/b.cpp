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
const int T = 102;
bool ok[T][T];
int n;
string s;

void build() {
    for(int i = 0; i < min(n,2); i++) {
        ok[i][i] = 1;
        char last = s[i];
        for(int j = i+1; j < n; j++) {
            ok[i][j] = (s[j] >= s[i]);
            if(ok[i][j]) last = s[j];
        }
    }
}

bool possible(int x) {
    for(int i = x+1; i < n; i++) {
        if(!ok[x][i] && !ok[x][i-1]) return false;
    }
    return true;
}

void print(int x) {
    for(int i = x; i < n; i++)
        if(ok[x][i]) cout << i+1 << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> s;
        n = s.size();
        build();
        bool ans = 0;
        for(int i = 0; i < min(n,2) && !ans; i++) {
            if(possible(i)) {
                ans = 1;
                cout << "yes" << endl;
                //print(i);
            }
        }
        if(!ans) cout << "no" << endl;
    }
    return 0;
}

