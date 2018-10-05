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
    string s; cin >> s;
    int sum = s[0] - '0';
    int cont = 0;
    while(s.size() > 1) {
        cont++; 
        for(int i = 1; i < s.size(); i++) { 
            sum += s[i] - '0';
        }
        s = to_string(sum);
        sum = s[0] - '0';
    }
    cout << cont << endl;

    return 0;
}

