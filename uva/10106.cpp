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
const int T = 1000;
int a[T];
int b[T];
int rest[T][T];
int ans[T][T];

void mult() {
    int k = 0;
    for(int i = 0; i+k < T; i++) {
        for(int j = 0; j < T; j++) {
            ans[i+k][j] += rest[i+k][j];
            ans[i+k][j] = (a[i]*b[i] + ans[i+k][j]) % 10;
            rest[i+k][j] += (a[i]*b[i] + ans[i+k][j]) / 10;
        }
        k++;
    }
    for(int i = 3; i >= 0; i--) cout << ans[i][1];
    cout << endl;
}

ii add() {
        for(int i = 0; i < T; i++) {
            for(int j = 1; j < T; j++) {
                ans[i][j] += ans[i][j-1];
            } 
        ll tmp = ans[T-1][T-1];
        ans[i][j] += tmp%10;
        tmp /= 10;
        tmp += ans[i][j]/10;
        ans[i][j] %= 10;
        for(int k = i+1; tmp != 0; k++) {
            ans[k][0] += tmp % 10;
            tmp /= 10;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    string aa, bb;
    while(getline(cin, aa)) {
        getline(cin, bb);
        cout << aa << " " << bb << endl;
        for(int i = aa.size() - 1; i >= 0; i--)
            a[i] = aa[i] - '0';
        for(int i = bb.size() - 1; i >= 0; i--)
            b[i] = bb[i] - '0';
        mult();
        add();
        for(int i = 20; i >= 0; i--) cout << ans[i][max(aa.size(), bb.size())];
        cout << endl;
    }
    return 0;
}

