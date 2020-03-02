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
const int T = 1e5 + 4;

string s;
string p;
int z[T];
int pi[T];
int ans[T];
vii v;

void go() {
    int l = 0, r = 0;
    int n = s.size();

    for(int i = 1; i < n; i++) {
        if(i <= r) z[i] = min(z[i-1], r-i+1);
        while(z[i] + i < n and s[z[i] + i] == s[z[i]]) z[i]++;
        if(r < i + z[i] - 1) l = i, r = i + z[i] - 1;
    }

    for(int i = 0; i < n; i++) cout << z[i] << " ";
    cout << endl;
}

void go2() {
    string p = s + "#";

    for(int i = 2; i <= p.size(); i++) {
        pi[i] = pi[i-1];
        while(pi[i] > 0 and p[pi[i]] != p[i-1]) pi[i] = pi[pi[i]];
        if(p[pi[i]] == p[i-1]) pi[i]++;
    }

    for(int i = 0; i <= p.size(); i++) cout << pi[i] << " ";
    cout << endl;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    go();
    go2();
    return 0;
}

