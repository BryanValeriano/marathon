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

const int T = 1e7 + 5;
bitset<T> crivo;
int ok;
ll ans;

void pre() {
    for(int i = 2; i < T; i++) {
        if(i == ok) break;
        if(!crivo[i]) {
            ans += i;
            for(int j = i+i; j < T; j+= i) crivo[j] = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> ok;
    pre();
    cout << ans << endl;
    return 0;
}

