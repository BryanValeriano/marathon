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
const int T = 2e5 + 10;
int bob;
int alice;
int both;
int n,b,a;

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> b >> a;
        bob = alice = both = 0;
        int aux;
        bool um,dois;
        for(int i = 0; i < n; i++) {
            um = dois = false;
            cin >> aux;
            if(aux % b == 0) um = true; 
            if(aux % a == 0) dois = true;
            if(um && dois) both++;
            else if(um) bob++;
            else if(dois) alice++;
        }
        if(both == 0) bob--;
        if(bob < 0) { cout << "ALICE" << endl; continue; }
        int play = 1;
        while(true) {
            if(play & 1) alice--;
            else bob--;
            play++;
            if(bob < 0) { cout << "ALICE" << endl; break; }
            if(alice < 0) { cout << "BOB" << endl; break; }
        }
    }
    return 0;
}

