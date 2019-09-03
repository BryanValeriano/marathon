#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    vector<int>divs;
    divs.pb(4);
    divs.pb(7);
    divs.pb(47);
    divs.pb(74);
    divs.pb(44);
    divs.pb(77);
    divs.pb(444);
    divs.pb(447);
    divs.pb(474);
    divs.pb(477);
    int num; cin >> num;
    for(int i = 0; i < divs.size(); i++) 
        if(num % divs[i] == 0) { cout << "YES" << endl; return 0; }
    cout << "NO" << endl; 
    return 0;
}

