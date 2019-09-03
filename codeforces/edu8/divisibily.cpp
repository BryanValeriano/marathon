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
string a,b;
int d,m;

bool check(int num, string s) {
    ll base = 1;
    ll acum = 0;
    vector<int> memo;
    set<int>vis;
    for(int i = s.size() - 1; i >= 0; i--) {
        if(!vis.count(base % num)) {
            vis.insert(base % num);
            memo.pb(base % num);
        }
        else break;
        base *= 10;
    }
    int j = 0;
    bool flag = false;
    for(int i = s.size() - 1; i >= 0; i--) {
        if(j == memo.size()) j = 0;
        if(memo[j] == 0) flag = true; 
        if(!flag) acum += (s[i] - '0') * memo[j];
        j++;
    }
    return (acum % num == 0);
}

bool isMagic(string s) {
    int casa = 1;
    for(int i = 0; i < s.size(); i++) {
        if(casa&1 and (s[i] - '0') == d) return false;
        if(!(casa&1) and (s[i] - '0') != d) return false;
        casa++;
    }
    return true;
}

void add(int casa) {
    if(a[casa] == '9') {
        a[casa] = '0';
        add(casa-1);
    } else a[casa]++;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> m >> d >> a >> b;

    ll ans = 0;

    while(a != b) { 
        if(check(m,a) and isMagic(a)) ans++;
        add(a.size()-1);
    }

    cout << ans << endl;
    return 0;
}

