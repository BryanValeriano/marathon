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
const int T = 1e3 + 10;
int v[T];

int main() {
    ios::sync_with_stdio(false);
    int n;
    ll s;
    cin >> n >> s;
    int mini = INF;
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
        mini = min(mini, v[i]);
    }
    if(sum < s) { cout << -1 << endl; return 0; }
    ll tot = 0;
    for(int i = 0; i < n; i++) 
        tot += v[i] - mini;
   
    if(tot >= s) { cout << mini << endl; return 0; }
    ll falta = s - tot;
    ll vezes = falta/n; 
    if(falta % n != 0) vezes++;
    cout << mini - vezes << endl;
    return 0;
}

