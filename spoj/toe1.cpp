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

struct mat { char m[3][3]; };

const int T = 2e5;
bool ok[T];
bool vis[T];

int key(const mat &x) {
    int ans = 0;

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++) {
            if(x.m[i][j] == 'X') ans += 2 * pow(3,(i*3)+j);
            else if(x.m[i][j] == 'O') ans += pow(3, (i*3)+j);
        }

    return ans;
}

bool isWin(const mat &x) {
    int ans = 0;
    int xx,oo;

    for(int i = 0; i < 3; i++) {
        xx = oo = 0;
        for(int j = 0; j < 3; j++) {
            if(x.m[i][j] == 'X') xx++;
            else if(x.m[i][j] == 'O') oo++;
        }
        if(xx == 3 or oo == 3) ans++;
    }

    for(int i = 0; i < 3; i++) {
        xx = oo = 0;
        for(int j = 0; j < 3; j++) {
            if(x.m[j][i] == 'X') xx++;
            else if(x.m[j][i] == 'O') oo++;
        }
        if(xx == 3 or oo == 3) ans++;
    }

    xx = oo = 0;
    for(int i = 0; i < 3; i++) {
        if(x.m[i][i] == 'X') xx++;
        else if(x.m[i][i] == 'O') oo++;
    }
    if(xx == 3 or oo == 3) ans++;

    xx = oo = 0;
    for(int i = 0; i < 3; i++) {
        if(x.m[i][2-i] == 'X') xx++;
        else if(x.m[i][2-i] == 'O') oo++;
    }
    if(xx == 3 or oo == 3) ans++;

    return ans >= 1;
}

void bfs(const mat &x) {
    queue< pair<mat,int> > bag;
    bag.push(mk(x,0));
    vis[key(x)] = 1;

    while(!bag.empty()) {
        pair<mat,int> tmp = bag.front();
        mat at = tmp.fi;
        int last = tmp.se;
        bag.pop();
                
        ok[key(at)] = 1;
        if(key(at) == 22) {
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) 
                    cout << at.m[i][j] << " ";
                cout << endl;
            }
            cout << endl << endl;
        }

        if(isWin(at)) continue;

        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++) {
                if(at.m[i][j] == '.') {
                    if(last == 0 or last == 2) {
                        at.m[i][j] = 'X';
                        if(!vis[key(at)]) {
                            bag.push(mk(at,1));
                            vis[key(at)] = 1;
                        }
                    } else if(last == 1) {
                        at.m[i][j] = 'O';
                        if(!vis[key(at)]) {
                            bag.push(mk(at,2));
                            vis[key(at)] = 1;
                        }
                    }
                    at.m[i][j] = '.';
                }
            }
    }
}

void pre() {
    mat x;

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            x.m[i][j] = '.';

    bfs(x);
}

int main() {
    ios::sync_with_stdio(false);
    pre();
    int tc; cin >> tc;
    mat x;
    while(tc--) {
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                cin >> x.m[i][j];
        if(ok[key(x)]) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}

