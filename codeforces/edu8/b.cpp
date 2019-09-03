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

int pegaUm(string s) {
    int x = 0;
    for(int i = 0; i < s.size(); i++) 
        if((s[i] - '0') % 4 == 0) x++;
    return x;
}

ll pegaDois(string s) {
    ll x = 0;
    bool flag;
    for(int i = 0; i < s.size(); i++) {
        int rest = 0;
        flag = false;
        for(int j = i; j <= i+1 and i+1 < s.size(); j++) {
            flag = true;
            if(j == i) rest += (((s[j] - '0')*10) % 4);
            else rest += ((s[j] - '0') % 4);
        }
        if(flag and rest % 4 == 0) x += (i + 1);
    }
    return x;
}


int main() {
    ios::sync_with_stdio(false);
    string s; cin >> s;
    ll ans = pegaUm(s);
    ans += pegaDois(s);
    cout << ans << endl;
    return 0;
}

