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

const int T = 2e5 + 10;
string v;
int troca[10];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    cin >> v;
    for(int i = 1; i <= 9; i++) cin >> troca[i];

    bool flag = false;
    for(int i = 0; i < n; i++) {
        if(flag) {
            if(troca[v[i]-'0'] >= v[i] - '0') v[i] = troca[v[i]-'0'] + '0';
            else break;
        }
        if(troca[v[i] - '0'] > v[i] - '0' and !flag) v[i] = troca[v[i]- '0'] + '0', flag = true;
    }
    cout << v << endl;
    return 0;
}

