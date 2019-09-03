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

const int T = 5e5 + 5;
int v[T];
int freq[T];
int ans[T];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];
    v[n] = 5e5 + 3;
    freq[v[n]] = -1;

    int l = 0;
    int r = 0;
    bool ok = 1;

    if(v[l] < 0) freq[abs(v[l])]--;

    while(l < n) {
        if(ok) {
            r++;
            if(v[r] > 0) {
                if(freq[v[r]] < 0) {
                    ans[l] = r-l;
                    ok = 0;
                }
            } else {
                freq[abs(v[r])]--;
            }
        } else {
            if(v[l] < 0) freq[abs(v[l])]++;
            l++;
            if(freq[v[r]] < 0) ans[l] = r-l;
            else ok = 1;
        }
    }

    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}

