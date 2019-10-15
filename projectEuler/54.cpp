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

string hand[2][7];
int um, dois;

string mask(string s) {
    if(s[0] == '2') s[0] = 'A';
    else if(s[0] == '3') s[0] = 'B';
    else if(s[0] == '4') s[0] = 'C';
    else if(s[0] == '5') s[0] = 'D';
    else if(s[0] == '6') s[0] = 'E';
    else if(s[0] == '7') s[0] = 'F';
    else if(s[0] == '8') s[0] = 'G';
    else if(s[0] == '9') s[0] = 'H';
    else if(s[0] == 'T') s[0] = 'I';
    else if(s[0] == 'J') s[0] = 'J';
    else if(s[0] == 'Q') s[0] = 'K';
    else if(s[0] == 'K') s[0] = 'L';
    else if(s[0] == 'A') s[0] = 'M';
    return s;
}
int suit(bool h) {
    int x = 0;
    for(int i = 1; i < 5; i++)
        if(hand[h][i][1] != hand[h][i-1][1]) x++;
    return x;
}

bool ord(bool h) {
    int x = 0;
    for(int i = 1; i < 5; i++)
        if(hand[h][i][0] != hand[h][i-1][0]+1) x++;
    return x;
}

int sum(bool h) {
    int ans = 0;
    for(int i = 0; i < 5; i++) ans += hand[h][i][0];
    return ans;
}

ii ofKind(bool h, int x, int prob) {
    for(int i = 0; i < 5; i++) {
        int y = 0;
        if(hand[h][i][0] == hand[h][prob][0]) continue;
        for(int j = i; j < 5; j++) if(hand[h][i][0] == hand[h][j][0]) y++;
        if(y == x) return mk(1,i);
    }
    return mk(0,0);
}

int mV(bool h) {
    int x = 0;
    for(int i = 0; i < 5; i++) x = max(x,(int)hand[h][i][0]);
    return x;
}

ii f(bool h, int x) {

    //royal flush
    if(x == 0) {
        bool ok = (!ord(h));
        ok &= (!suit(h));
        ok &= (sum(h) == 'I'+'J'+'K'+'L'+'M');
        return mk(ok,'M');
    }

    //straight flush
    else if(x == 1) {
        bool ok = (!ord(h));
        ok &= (!suit(h));
        return mk(ok,mV(h));
    }

    //four of a kind
    else if(x == 2) {
        ii z = ofKind(h,4,6);
        return mk(z.fi, hand[h][z.se][0]);
    }

    //full house
    else if(x == 3) {
        ii z = ofKind(h,3,6);
        if(z.fi) return mk(ofKind(h,2,z.se).fi, hand[h][z.se][0]);
        else return mk(0,0);
    }

    //flush
    else if(x == 4) {
        return mk(!suit(h), mV(h));
    }

    //straight
    else if(x == 5) {
        return mk(!ord(h), mV(h));
    }

    //three of a kind
    else if(x == 6) {
        ii z = ofKind(h,3,6);
        return mk(z.fi, hand[h][z.se][0]);
    }

    //two pairs
    else if(x == 7) {
        ii z = ofKind(h,2,6);
        if(z.fi) {
            ii y = ofKind(h,2,z.se);
            return mk(y.fi, max(hand[h][z.se][0], hand[h][y.se][0]));
        }
        else return mk(0,0);
    }

    //one pair
    else if(x == 8) {
        ii z = ofKind(h,2,6);
        return mk(z.fi, hand[h][z.se][0]);
    }
}

void kil() {
    for(int i = 4; i >= 0; i--) {
        if(hand[0][i][0] > hand[1][i][0]) { cout << 1 << endl; um++; return; }
        if(hand[0][i][0] < hand[1][i][0]) { cout << 2 << endl; dois++; return; }
    }

    cout << "UAT" << endl;
}

void solve() {
    ii a = mk(10,-1);
    ii b = mk(10,-1);

    for(int i = 0; i < 9; i++) if(f(0,i).fi) { a = mk(i,f(0,i).se); break; }
    for(int i = 0; i < 9; i++) if(f(1,i).fi) { b = mk(i,f(1,i).se); break; }


    int x = 0;
    int y = 0;

    cout << a.fi << " ";
    cout << b.fi << " | ";

    if(a.fi == b.fi) {
        if(a.fi ==  3 and b.fi == 3) {
            ii z = ofKind(0,3,6);
            ii y = ofKind(0,2,z.se);

            ii z2 = ofKind(1,3,6);
            ii y2 = ofKind(1,2,z2.se);

            z.se = hand[0][z.se][0];
            y.se = hand[0][y.se][0];

            z2.se = hand[1][z2.se][0];
            y2.se = hand[1][y2.se][0];

            if(z.se!= z2.se) {
                cout << (z.se > z2.se? 1 : 2) << endl;
                um += (z.se > z2.se);
                dois += (z.se < z2.se);
            }
            else if(y.se != y2.se) {
                cout << (y.se > y2.se? 1 : 2) << endl;
                um += (y.se > y2.se);
                dois += (y.se < y2.se);
            }
            else kil();
        } else {
            if(a.se == b.se) kil();
            else {
                cout << (a.se > b.se? 1 : 2) << endl;
                um += (a.se > b.se);
                dois += (a.se < b.se);
            }
        }
    }

    else {
        cout << (a.fi < b.fi? 1 : 2) << endl;
        um += (a.fi < b.fi);
        dois += (a.fi > b.fi);
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    hand[0][6][0] = hand[1][6][0] = '#';

    while(cin >> hand[0][0]) {
        hand[0][0] = mask(hand[0][0]);
        for(int i = 1; i < 5; i++) {
            cin >> hand[0][i];
            hand[0][i] = mask(hand[0][i]);
        }
        for(int i = 0; i < 5; i++) {
            cin >> hand[1][i];
            hand[1][i] = mask(hand[1][i]);
        }
        sort(hand[0], hand[0]+5);
        sort(hand[1], hand[1]+5);
        solve();
    }

    cout << um << endl;

    return 0;
}

