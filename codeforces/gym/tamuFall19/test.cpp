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
const int T = 100;

int main() {
    ios_base::sync_with_stdio(false);
    cout << T << " " << " " << T << " " << T << endl;
    for(int i = 0; i < T; i++) {
        for(int j = 0; j < T; j++) {
            for(int p = 0; p < T; p++) cout << "x";
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}

