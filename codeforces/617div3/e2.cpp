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

const int T = 30;
const int N = 2e5 + 5;
int best[T];
int ans[N];
set<ii> avail;
int n;
string s;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    cin >> s;

    for(int i = 0; i < n; i++) {
        int tmp = 0;
        for(int j = 0; j <= s[i]-'a'; j++) tmp = max(tmp, best[j]+1);
        best[s[i]-'a'] = tmp;
        avail.emplace(best[s[i]-'a'],i);
    }


    int col = 0;

    while(avail.size()) {
        ii at = *avail.rbegin();
        col++;
        
        while(avail.size()) {
            ans[at.se] = col;
            avail.erase(at);
            if(at.fi == 1) break;

            auto low = avail.lower_bound(mk(at.fi-1,0));
            while(low != avail.end() and low->fi == at.fi-1 and low->se <= at.se) low++;
            if(low != avail.begin()) low--;
            if(low != avail.end() and low->se < at.se) at = *low;
            else break;
        }
    }

    cout << col << endl;
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}

