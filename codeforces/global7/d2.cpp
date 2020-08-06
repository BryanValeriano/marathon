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
const int N = 1e6+6;
int pi[N];
string s,p,t,w;

void pre() {
    p += '#';
    pi[0] = pi[1] = 0;
    for(int i = 2; i <=p.size(); i++) {
        pi[i] = pi[i-1];
        while(pi[i] > 0 and p[pi[i]] != p[i-1]) pi[i] = pi[pi[i]];
        if(p[pi[i]] == p[i-1]) pi[i]++;
    }
}

string kmp(int op) {
    p = w;
    t = w;
    if(op) reverse(t.begin(),t.end());
    else reverse(p.begin(),p.end());
    pre();
    int k = 0;
    int m = p.size()-1;
    int ans = 0;

    for(int i = 0; i < t.size(); i++) {
        while(k>0 and p[k] != t[i]) k = pi[k];
        if(p[k]==t[i]) k++;
    }

    string r;
    for(int i = 0; i < k; i++) r += p[i];
    return r;
}


int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> s;
        w = "";
        if(s.size()==1) { cout << s << endl; continue; }
        int l = 0; int r = s.size()-1;
        while(l < r and s[l] == s[r]) l++, r--;
        string tmp,tmp2,x,y;
        for(int i = l; i <= r; i++) w += s[i];
        tmp = kmp(0);
        tmp2 = kmp(1);
        l--;r++;
        if(tmp.size() > tmp2.size()) tmp2 = tmp;
        for(int i = 0; i <= l; i++) x += s[i];
        for(int i = s.size()-1; i >= r; i--) y += s[i];
        reverse(y.begin(),y.end());
        cout << x+tmp2+y << endl;
    }
    return 0;
}

