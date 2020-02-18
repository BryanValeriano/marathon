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

const int N = 1e5 + 5;
const int T = 30;
ll qtd[N][T];
ll tmp[T][T];
 
int main() {
    ios_base::sync_with_stdio(false);
    string s; cin >> s;
    s = "#" + s;
    ll ans = 0;

    for(int i = 1; i < s.size(); i++) 
        qtd[i][s[i]-'a']++;
    
    for(int i = 1; i < s.size(); i++) {
        for(int j = 0; j < T; j++) {
            qtd[i][j] += qtd[i-1][j];
            ans = max(ans,qtd[i][j]);
        }
    }

    for(int i = 1; i < s.size(); i++) {
        int x = s[i] - 'a';
        for(int j = 0; j < T; j++) {
            tmp[x][j] += qtd[s.size()-1][j] - qtd[i][j];
            ans = max(ans,tmp[x][j]);
        }
    }
    
    cout << ans << endl;
    
    return 0;
}

