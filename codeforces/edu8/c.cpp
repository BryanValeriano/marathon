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

ll maxd(string s) {
    ll x = 0;
    for(int i = 0; i < s.size(); i++) 
        x += max(abs(s[i] - 'a'), abs(s[i] - 'z'));
    return x;
}

void print(string s, int k) {
    int atual = 0;
    int i;
    char best;
    for(i = 0; i < s.size(); i++) {
        if(abs(s[i] - 'z') > abs(s[i] - 'a')) best = 'z';
        else best = 'a';
        int dist = abs(s[i] - best);
        if(atual + dist <= k) { cout << best; atual += dist; }
        else break;
    }

    if(i < s.size()) {
        for(char j = 'a'; j <= 'z'; j++) 
            if(abs(s[i] - j) + atual == k) { cout << j; break; }
        i++;
    }

    for(; i < s.size(); i++) cout << s[i];
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    int n,k; cin >> n >> k;
    string s; cin >> s;
    ll up = maxd(s);
    if(k > up) { cout << -1 << endl; return 0; }
    print(s,k);
    return 0;
}

