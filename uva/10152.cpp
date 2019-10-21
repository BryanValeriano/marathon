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

const int T = 202;

map<string, int> id;
map<int, string> rev;
string nomes[T];
string s;

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        getline(cin,s);
        id.clear();
        rev.clear();
        for(int i = 0; i < n; i++) getline(cin,nomes[i]);
        for(int i = 1; i <= n; i++) getline(cin,s), id[s] = i, rev[i] = s;

        int ok = n;
        int ans = 0;

        for(int i = n-1; i >= 0; i--) if(id[nomes[i]] == ok) ok--;
        for(int i = ok; i >= 1; i--) cout << rev[i] << endl;
        cout << endl;
    }
    return 0;
}

