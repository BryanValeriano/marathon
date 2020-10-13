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
int n,k;
string s,t;


int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> s;
    t = s;
    for(int i = 0; i < n; i++) t[i] = s[i%k];
    if(t < s) {
        int p = k-1;
        while(s[p] == '9') p--;
        for(int i = p; i < k; i++) {
            int j = i;
            char c = (i==p? s[i]+1 : '0');
            while(j < n) t[j] = c, j += k;
        }
    }
    cout << n << endl << t << endl;
    return 0;
}

