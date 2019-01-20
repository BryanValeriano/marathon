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

int main() {
    ios::sync_with_stdio(false);
    string s; cin >> s;
    string ans;
    int atual = 0;
    while(atual < s.size() and s[atual] != '[') atual++;
    if(atual < s.size()) {
        ans += s[atual];
        int last = -1;
        while(atual < s.size()) {
            if(s[atual] == ']') last 

    return 0;
}

