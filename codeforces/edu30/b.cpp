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
int v[T];
int n;
string s;

map<int, set<int> > bag;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') v[i]++;
        else v[i]--;
        if(i != 0) v[i] += v[i-1];
        bag[v[i]].insert(i);
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        int quero;
        if(s[i] == '1') quero = v[i]-1;
        else quero = v[i]+1;


        if(bag.count(quero)) 
            ans = max(ans, (*bag[quero].rbegin()) - i + 1);
        
        bag[v[i]].erase(i);
        if(bag[v[i]].size() == 0) bag.erase(v[i]);
    }

    cout << ans << endl;
    
    return 0;
}

