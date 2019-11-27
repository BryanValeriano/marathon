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

bool check(int x) {

 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    int l = 0;
    int r = s.size() - 1;

    while(l <= r) {
        int mid = (l+r) >> 1;
        if(check(mid)) l = mid+1;
        else r = mid-1;
    }

    cout << l << endl;
    
    return 0;
}

