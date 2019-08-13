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

string ans = "aeiou";

int main() {
    ios::sync_with_stdio(false);
    int k; cin >> k;

    for(int i = 5; i <= k; i++) {
        if(k % i == 0 && k/i >= 5) {
            for(int start = 0; start < k/i; start++) {
                for(int j = 0; j < i; j++) 
                    cout << ans[(j+start)%5];
            }
            cout << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}

