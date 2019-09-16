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

vector<int> v;
int n;

int bin() {
    for(int i = v.size()-1; i >= 0; i--)
        if(v[i] <= i) return i+1;

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    int x;
    for(int i = 0; i < n; i++) cin >> x, v.pb(x);
    sort(v.begin(), v.end());
    cout << bin() << endl;
    return 0;
}

