#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int TAM = 2005;

bool cmp1(pair<int,int>&a, pair<int,int>&b) {
    return a.fi > b.fi;
}

bool cmp2(pair<int,int>&a, pair<int,int>&b) {
    return a.sec < b.sec;
}
    
int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int k; cin >> k;
    pair<int,int>row[TAM];
    for(int i = 0; i <= n; i++) {
        cin >> row[i].fi;
        row[i].sec = i+1;
    }
    sort(row, row + n, cmp1); 
    ll sum = 0;
    for(int i = 0; i < k; i++) 
        sum += row[i].fi;
    cout << sum << endl;
    sort(row, row + k, cmp2);
    int index = 0;
    for(int i = 0; i < k; i++) {
        if(i == k - 1) cout << n - index << endl; 
        else cout << row[i].sec - index << " ";
        index = row[i].sec;
    }
        

    return 0;
}

