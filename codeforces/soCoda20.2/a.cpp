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

vector<vector<int>> cols;
int n,m;

bool tent() {
    for(int i = 0; i < n; i++) {
        int wa = 0;
        for(int j = 0; j < m; j++) if(cols[j][i] != j+1) wa++;
        if(wa > 2) return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;

    for(int i = 0; i < m; i++) cols.pb(vector<int>(n));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> cols[j][i];

    bool ans = 0;
    ans |= tent();

    for(int i = 0; i < m; i++)
        for(int j = i+1; j < m; j++) {
            swap(cols[i],cols[j]);
            ans |= tent();
            swap(cols[i],cols[j]);
        }

    cout << (ans? "YES" : "NO") << endl;
    return 0;
}

