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
const int T = 5300;
int tmp[T + 10];
int n;
vector< bitset<T + 10> > v;
bitset<T + 10> tmp1[T + 10];
bitset<T + 10> tmp2[T + 10];
bitset<T + 10> vis[T + 10];

bool test(int x) {
    for(int i = 0; i < T; i++) vis[i].reset();

    for(int i = 1; i <= n; i++) {
        int xx = ceil((double)i / (double)x);
        for(int j = 1; j <= n; j++) {
            int yy = ceil((double)j / (double)x);
            if(! vis[xx][yy] ) {
                vis[xx][yy] = true;
                tmp1[xx][yy] = v[i-1][j-1];
            }
            else if(tmp1[xx][yy] != v[i-1][j-1]) {
                //cout << xx << " " << yy << " " << tmp1[xx][yy] << endl;
                //cout << i-1 << " " << j-1 << " " << v[i-1][j-1] << endl;
                return false;
            }
        }
    }
    return true;
}

bool test2(int x, int old) { 
    for(int i = 0; i < T; i++) vis[i].reset();

    for(int i = 1; i <= x; i++) {
        int xx = ceil((double)i / (double)x);
        for(int j = 1; j <= x; j++) {
            int yy = ceil((double)j / (double)x);
            if(! vis[i][j] ) {
                vis[i][j] = true;
                tmp2[xx][yy] = tmp1[i][j];
            }
            else if(tmp1[xx][yy] != tmp2[i][j]) {
                cout << xx << " " << yy << " " << tmp2[xx][yy] << endl;
                cout << i << " " << j << " " << tmp1[i][j] << endl;
                return false;
            }
        }
    }
    for(int i = 1; i <= x; i++)
        for(int j = 1; j <= x; j++)
            tmp1[i][j] = tmp2[i][j];
    return true;
}
    

int main() {
    cin.setf(ios::hex, ios::basefield);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> tmp[i];
        bitset<T + 10> x(tmp[i]);
        v.pb(x);
    }
    int ans = 1;
    for(int i = n; i >= 2; i--) { 
        if(n%i == 0) {
            if(test(i)) ans = i;
        }
    }
    int ans2 = ans;
    //if(ans != 1) 
    //    for(int i = ans+ans; i <= n; i += ans) {
    //        if(test2(i, ans2)) ans2 = i;
    //        else break;
    //    }
    cout << max(ans, ans2) << endl;
    return 0;
}

