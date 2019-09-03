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
int id[30];

int main() {
    ios::sync_with_stdio(false);
    string s; cin >> s;
    for(int i = 0; i < s.size(); i++) 
        id[s[i] - 'a']++;
    sort(id, id+27);
    int first = INF, pos = INF;
    for(int i = 0; i < 27; i++)
        if(id[i] != 0 and id[i] % 2 != 0) { first = id[i]; pos = i; break; }
    int ans = 1;
    for(int i = 0; i < 27; i++) 
        if(id[i] != 0 and i != pos and id[i] % 2 != 0) ans++;
    cout << (ans % 2 == 0? "Second" : "First") << endl;
    return 0;
}

