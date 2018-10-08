#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    string s; cin >> s;
    int cont = 0;
    for(int i = 0; i < s.size(); i++)
        if(s[i] == '4' or s[i] == '7')
            cont++;
    if(cont == 4 or cont == 7 or cont == 14 or cont == 17) cout << "YES";
    else cout << "NO";
    cout << endl;

    return 0;
}

