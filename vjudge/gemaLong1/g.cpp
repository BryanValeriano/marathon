#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 1e5 + 3;
int pi[T];
string a[3];
string t,p;
int h;

void pre() {
    p += '#';
    pi[0] = pi[1] = 0;
    for(int i = 2; i < (int)p.size(); i++) {
        pi[i] = pi[i-1];
        while(pi[i] > 0 and p[pi[i]] != p[i-1]) pi[i] = pi[pi[i]];
        if(p[pi[i]] == p[i-1]) pi[i]++;
    }
}

int kmp() {
    pre();
    int k = 0;
    int m = p.size()-1;

    for(int i = 0; i < (int)t.size(); i++) {
        while(k > 0 and p[k] != t[i]) k = pi[k];
        if(p[k] == t[i]) k++;
        if(k == m) return k;
    }
    return k;
}

int calc(string x, string y, string z) {
    int hh = h;
    t = x;
    p = y;
    int s = kmp();
    hh -= s;
    for(int i = s; i < (int)y.size(); i++) t += y[i];
    p = z;
    hh -= kmp();
    return hh;
}

int solve() {
    string x = "012";
    int ans = INF;
    do {
        ans = min(ans, calc(a[x[0]-'0'], a[x[1]-'0'], a[x[2]-'0']));
    } while(next_permutation(x.begin(), x.end()));

    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    while(cin >> a[0]) {
        cin >> a[1] >> a[2];
        h = a[0].size() + a[1].size() + a[2].size();
        cout << solve() << endl;
    }
    return 0;
}

