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
const ll INF = 0x3f3f3f3f3f3f3f;
int letras[30]; 
int tot;
string s;

ll solve(int div) {
    if(tot % div != 0) return INF;
    ll ans = 0;
    int gol = tot/div;

    for(int i = 0; i < div; i++) 
        ans += abs(letras[i] - gol);
    
    for(int i = div; i < 26; i++) 
        ans += letras[i];

    //cout << tot << " " << div << " | " << gol << " " << ans/2 << endl;
    return ans/2;
}

void conta() {
    for(int i = 0; i < s.size(); i++) 
        letras[s[i] - 'A']++;
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    getline(cin, s);
    while(tc--) {
        getline(cin, s);
        tot = s.size();
        memset(letras, 0, sizeof letras);
        conta(); 
        sort(letras, letras+27, greater<int>());
        ll ans = INF;
        for(int i = 1; i <= 26; i++)
            ans = min(ans, solve(i));
        cout << ans << endl;
    }
    return 0;
}

