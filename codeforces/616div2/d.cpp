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

const int T = 2e5 + 5;
const int N = 30;
int v[N][T];
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;

    for(int i = 0; i < s.size(); i++) v[s[i]-'a'][i+1]++;

    for(int i = 0; i < N; i++)
        for(int j = 1; j <= s.size(); j++)
            v[i][j] += v[i][j-1];

    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        if(l == r) { cout << "Yes" << endl; continue; }

        int qtd = 0;
        for(int i = 0; i < 30; i++)
            if(v[i][r] - v[i][l-1] > 0) qtd++;

        cout << (qtd > 1? "Yes" : "No") << endl;

    }

    return 0;
}

