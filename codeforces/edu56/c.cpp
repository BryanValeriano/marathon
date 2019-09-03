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
const ll INF = 2000000000000000000;
const int T = 2e5 + 10;
ll b[T];
ll a[T];
int n;

bool test() {
    bool flag = false;
    for(int i = 2; i <= n/2; i++) {
        while(a[i] < a[i-1]) {
            flag = true;
            a[i]++;
            a[n - i + 1]--;
        }
    }
    return flag;
}

bool corta() {
    ll mini = INF;
    bool flag = false;
    for(int i = n; i > n/2; i--) {
        if(a[i] > mini) {
            flag = true;
            a[n - i + 1] += (a[i] - mini);
            a[i] = mini;
        } else mini = a[i];
    }
    return flag;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n/2; i++) {
        cin >> b[i];
        if(i == 1) {
            a[i] = 0;
            a[n - i + 1] = b[i];
        }
        else if(b[i] >= a[n]) {
            a[n - i + 1] = a[n];
            a[i] = b[i] - a[n];
        }
        else {
            a[i] = 0;
            a[n - i + 1] = b[i];
        }
    }
    while(corta() or test()) continue;
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}

