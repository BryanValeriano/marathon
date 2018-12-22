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
const int num = 7;

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


int main() {
    ios::sync_with_stdio(false);
    string s; cin >> s;
    cout << (check(11,s)? "S" : "N") << endl;
    return 0;
}

