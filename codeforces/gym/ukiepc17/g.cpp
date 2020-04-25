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
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int N = 3;
vector<int> ai(N), af(N);
vector<int> bi(N), bf(N);

int mov[6][3] = { {1,0,0}, {-1,0,0}, {0,1,0}, {0,-1,0}, {0,0,1}, {0,0,-1} };

void swp() {
    int cord;
    for(int i = 0; i < N; i++)
        if(ai[i] == bi[i]) cord = i;
    bi[cord] += 1;
}

vector<int> gol(const vector<int> &x, int k) {
    vector<int> tmp(N);
    tmp[0] = x[0]+mov[k][0];
    tmp[1] = x[1]+mov[k][1];
    tmp[2] = x[2]+mov[k][2];
    return tmp;
}

int dist(const vector<int> &x, const vector<int> &y) {
    return (abs(x[0]-y[0]) + abs(x[1]-y[1]) + abs(x[2]-y[2]));
}

bool close(const vector<int> &x, const vector<int> &y, int k) {
    vector<int> tmp = gol(x,k);
    return dist(x,y) > dist(tmp,y);
}

void print(vector<int> &x, char y) {
    cout << "(";
    for(int i = 0; i < N; i++) cout << x[i] << (i+1 < N? " " : ")");
    cout << y;
}

bool blz() {
    return (ai == af and bi == bf);
}

int main() {
    ios_base::sync_with_stdio(false);
    for(int i = 0; i < N; i++) cin >> ai[i];
    for(int i = 0; i < N; i++) cin >> af[i];
    for(int i = 0; i < N; i++) cin >> bi[i];
    for(int i = 0; i < N; i++) cin >> bf[i];

    while(!blz()) {
        print(ai,' ');
        print(bi,'\n');
        bool ok = 0;
        for(int k = 0; k < 6; k++) {
            if(close(ai,af,k)) {
                vector<int> x = gol(ai,k);
                if(x != bi) { ai = x; ok = 1; break; }
            }
        }
        for(int k = 0; k < 6; k++) {
            if(close(bi,bf,k)) {
                vector<int> x = gol(bi,k);
                if(x != ai) { bi = x; ok = 1; break; }
            }
        }
        if(!ok) swp();
    }
    print(ai,' ');
    print(bi,'\n');

    return 0;
}

