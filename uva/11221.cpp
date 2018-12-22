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
const int T = 110;
map<int,int> sqr;
char g[T][T];

void mkSqr() {
    for(int i = 1; i*i <= 1e4; i++) 
        sqr[i*i] = i;
}

string test1(string s, int n) {
    string x;
    for(int j = 0; j < n; j++)
        for(int i = 0; i < n; i++)
            x += g[i][j];
    return x;
}
string test2(string s, int n) {
    string x;
    for(int i = n-1; i >= 0; i--) 
        for(int j = n-1; j>= 0; j--)
            x += g[i][j];
    return x;
}
string test3(string s, int n) {
    string x;
    for(int j = n-1; j >= 0; j--)
        for(int i = n-1; i >= 0; i--)
            x += g[i][j];
    return x;
}

bool test(string s) {
    int n = sqr[(int)s.size()];
    int it = 0;
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++) 
            g[i][j] = s[it++];
    string a = test1(s,n);
    string b = test2(s,n);
    string c = test3(s,n);
    return(s == a and s == b and s == c);
}
    

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    int cont = 0;
    string lixo;
    getline(cin,lixo);
    mkSqr();
    while(tc--) {
        string tmp;
        string s;
        getline(cin,tmp);
        for(int i = 0; i < tmp.size(); i++) 
            if(tmp[i] >= 'a' and tmp[i] <= 'z') s += tmp[i];
        cout << "Case #" << ++cont << ":" << endl;
        if(sqr.count((int)s.size()) and test(s))
            cout << sqr[(int)s.size()] << endl;
        else cout << "No magic :(" << endl;
    }
    return 0;
}

