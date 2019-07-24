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

int b,w;

void build(int op) {
    int inix = 1, iniy;
    iniy = (op == 1? 3 : 4);
    if(b < w) swap(b,w);
    
    b--;
    cout << inix << " " << iniy << endl;
    inix++;

    while(b > 0 and w > 0 and b > w) {
        cout << inix << " " << iniy << endl;
        w--;
        if(b > w) { cout << inix+1 << " " << iniy << endl; b--; } 
        if(b > w) { cout << inix << " " << iniy+1 << endl; b--; } 
        if(b > w) { cout << inix << " " << iniy-1 << endl; b--; } 
        inix += 2;
    }

    while(b or w) {
        if(w) cout << inix << " " << iniy << endl, w--;
        if(b) cout << inix+1 << " " << iniy << endl, b--;
        inix += 2;
    }
}
    

int main() {
    ios::sync_with_stdio(false);

    int q; cin >> q;
    while(q--) {
        cin >> b >> w;
        if(b >= w) {
            if(w*3 + 1 < b) cout << "NO" << endl;
            else { cout << "YES" << endl; build(0); }
        } else  {
            if(b*3 + 1 < w) cout << "NO" << endl;
            else { cout << "YES" << endl; build(1); }
        }
    }

    return 0;
}

