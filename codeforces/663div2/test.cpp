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
vector<int> v;
int n;

bool cycle() {
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
            for(int k = j+1; k < n; k++)
                if(v[j] < v[k] and v[j] < v[i]) return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    int ans = 0, ans2 = 0;
    for(int i = 1; i <= n; i++) v.pb(i);
    do {
        if(!cycle()) {
            for(int i = 0; i < n; i++) cout << v[i] << " ";
            cout << endl;
            ans2++;
        } else ans++;
    } while(next_permutation(v.begin(),v.end()));
    cout << ans << " " << ans2 << endl;
    return 0;
}

