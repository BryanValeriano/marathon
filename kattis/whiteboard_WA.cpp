#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<char,int> ci;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<ci> vci;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int h,w,n;
int ok;
int nok;
int gol;
vector<string> need;
vector<vector<bool>> use;
vci commands;
vii ori;
int maxi = -1;
int mini = INF;

ii mov(char a) {
    if(a == 'u') return mk(-1,0);
    if(a == 'd') return mk(1,0);
    if(a == 'l') return mk(0,-1);
    return mk(0,1);
}

ci inverse(char a, int x) {
    if(a == 'u') a = 'd';
    else if(a == 'd') a = 'u';
    else if(a == 'r') a = 'l';
    else if(a == 'l') a = 'r';
    return mk(a,x);
}

ii paint(ii last, char a, int k, int op) {
    int x = last.fi;
    int y = last.se;
    ii mv = mov(a);
    while(k--) {
        x += mv.fi;
        y += mv.se;
        if(!op) {
            if(use[x][y]) continue;
            use[x][y] = 1;
            if(need[x][y] == '#') ok++;
            else nok++;
        } else {
            op--;
            if(use[x][y]) {
                use[x][y] = 0;
                if(need[x][y] == '#') ok--;
                else nok--;
            }
            if(ok == gol and nok == 0) {
                maxi = max(maxi,op);
                mini = min(mini,op);
            }
        }
    }
    return mk(x,y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> h >> w >> n;

    for(int i = 0; i < h; i++) {
        string s; cin >> s;
        need.pb(s);
        use.pb(vector<bool>(w,0));
        for(int j = 0; j < w; j++)
            if(need[i][j] == '#') gol++;
    }

    if(gol == 0) mini = 0, maxi = 0;

    ii last = mk(h-1,0);
    use[h-1][0] = 1;
    if(need[h-1][0] == '#') ok++;
    else nok++;

    int op = 1;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        int x; cin >> x;
        op += x;
        last = paint(last,s[0],x,0);
        ori.pb(last);
        commands.pb(inverse(s[0],x));
        if(commands.back().fi == 'u') ori.back().fi++;
        else if(commands.back().fi == 'd') ori.back().fi--;
        else if(commands.back().fi == 'l') ori.back().se++;
        else if(commands.back().fi == 'r') ori.back().se--;
    }



    if(ok == gol and nok == 0) {
        maxi = max(maxi,op);
        mini = min(mini,op);
    }

    for(int i = n-1; i >= 0; i--) {
        paint(ori[i],commands[i].fi,commands[i].se,op);
        op -= commands[i].se;

        //for(int k = 0; k < h; k++) {
        //    for(int j = 0; j < w; j++) cout << use[k][j];
        //    cout << endl;
        //}
        //cout << endl;
    }

    if(ok == 1 and nok == 0 and gol == 1 and use[h-1][0] == 1) {
        mini = min(mini,0);
        maxi = max(maxi,0);
    }

    if(maxi == -1) {
        cout << "-1 -1" << endl;
    } else cout << mini << " " << maxi << endl;

    return 0;
}

