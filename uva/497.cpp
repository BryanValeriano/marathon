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

const int T = 1e6;
int dp[T];
int choose[T];
int v[T];
int n;
int last;

int solve() {
    int best = 0;
    for(int k = 1; k < n; k++) {
        choose[k] = k;
        dp[k] = 1;

        for(int i = 1; i < k; i++) {
            if(v[i] < v[k] and dp[i] + 1 > dp[k]) {
                dp[k] = dp[i] + 1;
                choose[k] = i;
            }
        }

        if(dp[k] > best) {
            best = dp[k];
            last = k;
        }

    }

    return best;
}

void build(int at) {
    if(choose[at] == at) {
        cout << v[at] << endl;
        return;
    }
    else build(choose[at]);
    cout << v[at] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    int tc;
    string s;
    cin >> tc;
    getline(cin,s);
    getline(cin,s);

    while(tc--) {
        n = 1;
        while(getline(cin,s) and s != "") v[n++] = stoi(s); 
        cout << "Max hits: " << solve() << endl;
        build(last);
        if(tc) cout << endl;
    }
    return 0;
}

