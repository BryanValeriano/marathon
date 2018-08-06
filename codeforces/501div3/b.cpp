#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
bool val = false;
vector<int>resp;
string t;
string s;
int n;

int find(int comeco, char alvo) {
    //cout << s[comeco] << " " << alvo << endl;
    for(int i = comeco; i < n; i++) 
        if(s[i] == alvo) return i;
    return -1;
}

void swapp(int a, int b) {
    for(int i = b; i > a; i--) {
        swap(s[i], s[i-1]);
        resp.pb(i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> s >> t;

    for(int i = 0; i < n; i++) {
        if(s[i] != t[i]) {
            int pos = find(i, t[i]);
            if(pos == -1) {cout << -1 << endl; return 0;}
            else swapp(i, pos);
        }
    }
    cout << resp.size() << endl;
    for(int a : resp) cout << a << " ";
    cout << endl;

    return 0;
}

