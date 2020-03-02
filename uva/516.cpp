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
const int T = 2e2;

vector<int> split(string s) {
    string x;
    vector<int> v;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ') v.pb(stoi(x)), x = "";
        else x += s[i];
    }
    if(x.size()) v.pb(stoi(x));

    return v;
}

int calc(vector<int> &v) {
    int ans = 1;
    for(int i = 0; i < v.size(); i += 2)
        while(v[i+1]) ans *= v[i], v[i+1]--;
    return ans;
}

vector<int> decop(int x) {
    vector<int> v;
    for(int i = 2; i*i <= x; i++) {
        ii tmp = mk(i,0);
        while(x % i == 0) x /= i, tmp.se++;
        if(tmp.se) v.pb(tmp.se), v.pb(tmp.fi);
    }
    if(x > 1) v.pb(1), v.pb(x);
    reverse(v.begin(), v.end());
    return v;
}


int main() {
    ios_base::sync_with_stdio(false);
    string s;
    getline(cin,s);
    while(s != "0") {
        vector<int> v = split(s);
        int x = calc(v);
        x--;
        v = decop(x);
        for(int i = 0; i < v.size(); i++)
            cout << v[i] << (i+1 < v.size()? " " : "\n");
        getline(cin,s);
    }



    return 0;
}

