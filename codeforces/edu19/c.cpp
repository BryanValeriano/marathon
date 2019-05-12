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

int track[33];
string s,u;

int main() {
    ios::sync_with_stdio(false);
    cin >> s;

    for(int i = 0; i < s.size(); i++) 
        track[s[i] - 'a']++;

    int at = 0;
    int i = 0;
    stack<char> t;

    while(!track[i]) i++;

    while(at < s.size()) {
        track[s[at] - 'a']--;
        while(!t.empty() and t.top() - 'a' <= i) u += t.top(), t.pop();
        if((s[at] - 'a') == i) u += s[at];
        else t.push(s[at]);
        while(!track[i] and i < 33) i++;
        at++;
    }

    while(!t.empty()) u += t.top(), t.pop();
    cout << u << endl;

    return 0;
}

