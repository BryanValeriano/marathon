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
const int T = 10;
int v[T];
int n,m;

bool check() {
    int cont = 0;
    int max = 0, pos = 0;

    for(int i = 0; i < n; i++) {
        if(v[i] > max) max = v[i], pos = i;
        for(int j = i+1; j < n; j++)
            if(v[i]==v[j]) cont++;
    }

    if(cont != 1 or pos == 0 or pos == n-1) return false;

    for(int i = 1; i <= pos; i++)
        if(v[i] <= v[i-1]) return false;
    for(int i = n-2; i >= pos; i--)
        if(v[i] <= v[i+1]) return false;

    for(int i = 0; i < n; i++) cout << v[i] << " ";
    cout << endl;

    return true;
}

// 1 2 3 4 3 2 1

int solve(int pos) {
    if(pos==n) return check();
    int ans = 0;
    for(int i = 1; i <= m; i++) {
        v[pos] = i;
        ans += solve(pos+1);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    cout << solve(0) << endl;
    return 0;
}

