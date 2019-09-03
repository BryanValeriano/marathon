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

const int T = 1e5 + 3;

multiset<ll> bag;
map<ll,ll> qtd;

ll ch[T][4];

ll gen() {
    for(int i = 0; i < T; i++) ch[i][0] = 1;
    for(int j = 0; j <= 3; j++) ch[j][j] = 1; 

    for(int i = 1; i < T; i++)
        for(int j = 1; j <= 3; j++)
            ch[i][j] = ch[i-1][j-1] + ch[i-1][j];
}

int main() {
    ios::sync_with_stdio(false);
    gen();
    int n; cin >> n;
    ll x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        bag.insert(x);
        qtd[x]++;
    }

    ll a,b,c;
    a = *bag.begin(); 
    bag.erase(bag.begin());
    b = *bag.begin(); 
    bag.erase(bag.begin());
    c = *bag.begin(); 
    bag.erase(bag.begin());
   
    int aa = 1;
    int bb = 1;
    int cc = 1;

    if(a == b) aa++, bb--;
    else if(b == c) bb++, cc--;
    if(a == c) aa++, cc--;

    ll ans = ch[qtd[a]][aa] * ch[qtd[b]][bb] * ch[qtd[c]][cc];
    cout << ans << endl;

    return 0;
}

