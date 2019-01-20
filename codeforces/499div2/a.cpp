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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    sort(s.begin(), s.end());
    char last = s[0]; 
    string ans;
    ans += s[0];
    for(int i = 1; i < n and ans.size() < k; i++) {
        if(s[i] - last > 1) {
            ans += s[i];
            last = s[i];
        }
    }
    
    int resp = 0;
    for(int i = 0; i < ans.size(); i++) resp += ans[i] - 'a' + 1;
    cout << (ans.size() == k? resp : -1) << endl; 

    return 0;
}

