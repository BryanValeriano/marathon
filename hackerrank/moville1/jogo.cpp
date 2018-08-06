#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int TAM = 1e7+3;
vector<int,ll> inter[TAM]; 

void inserbin(int tmp1, int tmp2, int val) {
    

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int k; cin >> k;
    for(int i = 0; i < k; i++) {
        int tmp1, tmp2
        ll val;
        cin >> tmp1 >> tmp2 >> val;
        inserbin(tmp1,tmp2, val);
    }

    ll maxx = 0;
    for(int i = 0; i < inter.size(); i++)
        maxx = max(maxx, inter[i].sec);
    cout << maxx << endl;
    return 0;
}

