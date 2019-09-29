#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int need[30];
int have[30];

int main() {
    ios_base::sync_with_stdio(false);
    int n,k; cin >> n >> k;
    string s,t;;
    getline(cin,s);
    getline(cin,s);
    cin >> t;

    for(int i = 0; i < s.size(); i++) if(s[i] != ' ') have[s[i]-'a']++;
    for(int i = 0; i < t.size(); i++) need[t[i]-'a']++;

    int ans = INF;
    for(int i = 0; i < 30; i++)
        if(need[i])
            ans = min(ans,(have[i]? have[i]/need[i] : 0));

    cout << ans << endl;

    return 0;
}

