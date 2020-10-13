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
const int T = 3e4+4;
const int N = 102;
int v[N];
bool ok[T];


int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> v[i];
        ok[v[i]] = 1;
    }

    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
            if(ok[v[i]+v[j]]) {
                cout << "SIM" << endl;
                return 0;
            }

    cout << "NAO" << endl;
    return 0;
}

