#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
set<char>ind;
string t;
string resp;

void rem(string s) {
    for(int i = 0; i < s.size(); i++) 
        if(!ind.count(s[i]))
            t += s[i];
}

void pont() {
    for(int i = 0; i < t.size(); i++) {
        resp += '.';
        resp += t[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    string s; cin >> s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    ind.insert('a');
    ind.insert('e');
    ind.insert('i');
    ind.insert('o');
    ind.insert('u');
    ind.insert('y');
    rem(s);
    pont();
    cout << resp << endl; 
    return 0;
}

