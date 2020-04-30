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
map<string,int> freq;

int main() {
    ios_base::sync_with_stdio(false);
    int n; string s;
    cin >> n >> s;
    string aux;
    aux = s[0];
    aux += "#";
    int best = 0;
    string ans;
    for(int i = 1; i < n; i++) {
        aux[1] = s[i];
        freq[aux]++;
        if(freq[aux] > best) ans = aux, best = freq[aux];
        aux[0] = aux[1];
    }
    cout << ans << endl;
    return 0;
}

