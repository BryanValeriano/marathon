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

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    string s; cin >> s;
    string t;
    int i = 0;
    int cont = 1;
    while(i < s.size()) {
        t += s[i];
        i += cont;
        cont++;
    }
    cout << t << endl;

    return 0;
}

