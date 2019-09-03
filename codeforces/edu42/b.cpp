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
int n;
string s;

bool poe(char x, int pos) {
    if(pos - 1 >= 0 and s[pos-1] == x) return false;
    if(pos + 1 < n and s[pos+1] == x) return false;
    s[pos] = x;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    int a, b; cin >> n >> a >> b;
    int tot = a + b;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != '*') {
            if((a > 0 and a > b and poe('a',i)) or (b == 0 or !poe('b',i)) and a > 0 and poe('a',i)) a--;
            else if(b > 0 and poe('b', i)) b--;
        }
    }
    cout << tot - (a+b) << endl;

    return 0;
}

