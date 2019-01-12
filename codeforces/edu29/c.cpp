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
ll plays;
ll a,b;
int x,y;
int alice[4][4];
int bob[4][4];
bool vis[4][4];

struct mov {
    int x,y,a,b;

    mov(int x, int y, int a, int b) :
        x(x), y(y), a(a), b(b) {}
};

vector<mov> track;
vector<ii> ciclo;

void monta(int x, int y) {
    int ini = INF;
    for(int i = 0; i < track.size(); i++)
        if(track[i].x == x and track[i].y == y) {
            ini = i; break;
        }

    for(int i = ini; i < track.size(); i++)
        ciclo.eb(track[i].a, track[i].b);
    
    for(int i = 1; i < ciclo.size(); i++) {
        ciclo[i].fi += ciclo[i-1].fi;
        ciclo[i].se += ciclo[i-1].se;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> plays >> x >> y;

    for(int i = 1; i <= 3; i++)
        for(int j = 1; j <= 3; j++)
            cin >> alice[i][j];

    for(int i = 1; i <= 3; i++)
        for(int j = 1; j <= 3; j++)
            cin >> bob[i][j];

    ll jogadas = 0; 
    while(jogadas < plays and !vis[x][y]) {
        vis[x][y] = true;
        int movA = x;
        int movB = y;
        int winA, winB;
        winA = 0;
        winB = 1;
        if(movA == 3 and movB == 2) { winA = 1; winB = 0; }
        else if(movA == 2 and movB == 1) { winA = 1; winB = 0; }
        else if(movA == 1 and movB == 3) { winA = 1; winB = 0; }
        else if(movA == movB) winB = 0;
        track.pb(mov(x,y,winA, winB));
        x = alice[movA][movB];
        y = bob[movA][movB];
        jogadas++;
        a += winA;
        b += winB;
        if(jogadas == plays and !vis[x][y]) x = y = -1; 
    }

    monta(x,y);
    if(ciclo.size()) {
        ll fulla = ciclo.rbegin()->fi;
        ll fullb = ciclo.rbegin()->se;
        int size = ciclo.size();
        ll cabe = (plays - jogadas) / size;
        a += cabe * fulla;
        b += cabe * fullb;
        if( (plays - jogadas) % size != 0) {
            cabe++;
            int last = (plays - jogadas) % size;
            a += ciclo[last-1].fi;
            b += ciclo[last-1].se;
        }
    }
    cout << a << " " << b << endl;



    //for(auto x : track) cout << "(" << x.x << "," << x.y << ")" << " | " << x.a << " " << x.b << endl;
    //for(auto x : ciclo) cout << "(" << x.fi << "," << x.se << ")" << " ";
    //cout << endl;
    return 0;
}

