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
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
int v[5];

bool ok(int x) {
    for(int i = 0; i < 3; i++)
        if(x > v[i]) return false;

    int impar = 0;
    for(int i = 0; i < 3; i++)
        impar += ((v[i]-x)&1);

    impar += ((v[3]+x)&1);

    return (impar < 2);
}

bool zero() {
    int mini = INF;
    for(int i = 0; i < 3; i++) mini = min(mini,v[i]);
    return ok(mini);
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        for(int i = 0; i < 4; i++) cin >> v[i];
        bool ans = 0;

        for(int i = 0; i < 100; i++)
            ans |= ok(i);

        ans |= zero();
        cout << (ans? "Yes" : "No") << endl;
    }
    return 0;
}

