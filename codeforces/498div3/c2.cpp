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
const int T = 2e5;
int ve[T];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        cin >> ve[i];
    ll esq = 0, dir = 0, pontE = 0, pontD = n-1, resp = 0;
    while(pontE <= pontD) {
        if(esq <= dir) esq += ve[pontE++];
        else if(esq > dir) dir += ve[pontD--];
        if(esq == dir) resp = esq;
    }
    cout << resp << endl;
    return 0;
}

