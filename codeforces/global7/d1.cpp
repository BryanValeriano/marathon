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
string s;
bool pal(string x) {
    string y = x;
    reverse(x.begin(),x.end());
    return (x==y);
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> s;
        if(s.size()==1) { cout << s << endl; continue; }
        int l = 0; int r = s.size()-1;
        while(l < r and s[l] == s[r]) l++, r--;
        string tmp,tmp2,x,y;
        for(int i = l; i <= r; i++) {
            tmp += s[i];
            if(pal(tmp)) tmp2 = tmp;
        }
        tmp = "";
        for(int i = r; i >= l; i--) {
            tmp += s[i];
            if(pal(tmp) and (tmp.size() > tmp2.size())) tmp2 = tmp;
        }
        l--;r++;
        for(int i = 0; i <= l; i++) x += s[i];
        for(int i = s.size()-1; i >= r; i--) y += s[i];
        reverse(y.begin(),y.end());
        cout << x+tmp2+y << endl;
    }
    return 0;
}

