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
const int T = 1e5 + 10;
int beg[T];
int acaba[T];
vector<int> ida;
vector<int> volta;
int n, x, y;
int mini = INF;

void solve() {
    for(int i = 0; i < n; i++) {
        int start = lower_bound(ida.begin(), ida.end(), beg[i]) - ida.begin();
        int fim = lower_bound(volta.begin(), volta.end(), acaba[i]) - volta.begin();
        if(start >= x) start--;
        while(ida[start] > beg[i] and start > 0) start--;
        if(fim >= y) continue;
        start = ida[start];
        fim = volta[fim];
        if(start > beg[i] or fim < acaba[i]) continue;
        mini = min(mini, fim - start + 1);
    }
}

void read() {
    cin >> n >> x >> y;
    int aux;
    for(int i = 0; i < n; i++)
        cin >> beg[i] >> acaba[i];
    for(int i = 0; i < x; i++) { cin >> aux; ida.pb(aux); }
    for(int i = 0; i < y; i++) { cin >> aux; volta.pb(aux); }

    sort(ida.begin(), ida.end());
    sort(volta.begin(), volta.end());
}

int main() {
    ios::sync_with_stdio(false);
    read();
    solve();
    cout << mini << endl;
    return 0;
}

