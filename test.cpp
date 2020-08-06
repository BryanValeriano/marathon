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

const int T = 1e7+2;
int v[T];

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];
    int l = 0;
    int r = 1;
    while(r < n) {
        if(v[l] != v[r]) l++, r++;
        else {
            l++;
            r++;
            while(r < n and v[l] == v[r]) r++;
            if(r < n) {
                swap(v[l],v[r]);
                l++;
                if(l==r) r++;
            }
        }
    }

    for(int i = 0; i < n; i++) cout << v[i] << " ";
    cout << endl;


    return 0;
}

