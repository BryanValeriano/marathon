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
int n, h;
int v[T];

void solve() {
    int q;
    cin >> q;
    int track = 0;
    bool pick = false;
    while(q) {
        // move left
        if(q == 1) 
            if(track > 0) track--; 

        // move right
        if(q == 2)  
            if(track < n-1) track++;
        

        // pick up box
        if(q == 3) {
            if(pick == false) {
                if(v[track] > 0) {
                    pick = true;
                    v[track]--;
                }
            }
        }

        // drop box
        if(q == 4) { 
            if(pick == true) { 
                if(v[track] + 1 <= h) {
                    pick = false;
                    v[track]++;
                }
            }
        }
        cin >> q;
    }
}

void read() {
    cin >> n >> h;
    for(int i = 0; i < n; i++)
        cin >> v[i];
}

void print() {
    for(int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    read();
    solve();
    print();
    return 0;
}

