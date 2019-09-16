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

const int T = 102;
int b[T];
int a[T];
bool ok[T];

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        char tmp;
        cin >> tmp;
        ok[i] = (tmp == '1');
    }
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];

    int ans = 0;

    for(int p = 0; p < 10000; p++) {
        int x= 0;
        for(int i = 0; i < n; i++) {
            if(p >= b[i] and (!((p-b[i]) % a[i]))) ok[i] = !ok[i];
            x += ok[i];
        }
        ans = max(ans,x);
    }

    cout << ans << endl;

    return 0;
}

