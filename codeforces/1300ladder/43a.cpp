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
    int n; cin >> n;
    int cont1 = 0;
    int cont2 = 0;
    string s1;
    string s2;
    string tmp; 
    cin >> s1;
    cont1++;
    for(int i = 1; i < n; i++) {
        cin >> tmp;
        if(tmp == s1) cont1++;
        else {
            s2 = tmp;
            cont2++;
        }
    }
    cout << (cont1 > cont2? s1 : s2) << endl; 

    return 0;
}

