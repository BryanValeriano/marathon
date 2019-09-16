#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

vector<int> ans;

int main() {
    ios_base::sync_with_stdio(false);
    int sob,dec;
    cin >> sob >> dec;

    if(sob >= dec) {
        int x = dec;
        int passo = 0;
        while(x >= 1) {
            for(int i = 1; i <= sob; i++) ans.pb(x), x += dec;
            passo++;
            x = dec-passo;
        }
    } else {
        int top = sob*dec;
        int x = top-sob+1;
        int passo = sob-1;
        while(x <= top) {
            for(int i = 1; i <= dec; i++) ans.pb(x), x -= sob;
            passo--;
            x = top-passo;
        }
    }

    cout << ans.size() << endl;
    for(auto ok : ans) cout << ok << " ";
    cout << endl;

    return 0;
}

