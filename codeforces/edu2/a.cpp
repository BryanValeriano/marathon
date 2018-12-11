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
const int T = 1e5 + 10;

bool isDigit(string x) {
    for(int i = 0; i < x.size(); i++) {
        if(x[i] >= '0' and x[i] <= '9') continue;
        else return false;
    }
    if(x[0] == '0' and x.size() != 1) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    string s; cin >> s;
    vector<string> digit;
    vector<string> rest;
    string x;
    for(int i = 0; i < s.size(); i++) { 
        if(i > 0 and (s[i] == ',' and s[i-1] == ',') or (s[i] == ';' and s[i-1] == ';')) 
            rest.pb(",");
        else if(s[i] == ',' or s[i] == ';') {
            if(isDigit(x)) digit.pb(x);
            else rest.pb(x);
            x = "";
        }
        else x += s[i];
    }
    if(x != "" and isDigit(x)) digit.pb(x);
    else rest.pb(x);
    if(digit.size() != 0) {
        cout << "\"";
        for(int i = 0; i < digit.size(); i++) {
            cout << digit[i];
            if(i + 1 < digit.size()) cout << ",";
        }
        cout << "\"";
        cout << endl;
    } else cout << "-" << endl;
    if(rest.size() != 0) {
        cout << "\"";
        for(int i = 0; i < rest.size(); i++) {
            cout << rest[i];
            if(i + 1 < rest.size() && rest[i] != "," && rest[i+1] != ",") cout << ",";
        }
        cout << "\"";
        cout << endl;
    } else cout << "-" << endl;
    return 0;
}

