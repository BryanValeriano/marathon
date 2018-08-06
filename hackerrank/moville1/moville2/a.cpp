#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    set<string> tel;
    string tmp;
    while(n--) {
        cin >> tmp;
        tel.insert(tmp);
    }
    int m; cin >> m;
    while(m--) {
        cin >> tmp;
        set<string>::iterator it;
        it = tel.find(tmp);
        (it != tel.end())? cout << "NOK": cout << "OK";
        cout << endl;
    }

    return 0;
}

