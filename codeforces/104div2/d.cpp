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
int a1,b1,a2,b2,a3,b3,a4,b4;

string gen(char last) {
    string quatro = "4";
    string sete = "7";
    if(last == '4' and a3 and a2) {
        a3--;
        a2--;
        return sete += gen('7');
    }
    else if(last == '7' and a4 and a1) {
        a1--;
        a4--;
        return quatro += gen('4');
    }
    return "";
}


int main() {
    ios::sync_with_stdio(false);
    cin >> a1 >> a2 >> a3 >> a4;
    b1 = a1; b2 = a2; b3 = a3; b4 = a4;

    bool okx = false;
    bool oky = false;

    string quatro = "4";
    string sete = "7";

    a1--;
    string x = quatro += gen('4');
    if(!a3 and !a4) {
        string k;
        for(int i = x.size() - 1; i >= 0; i--) {
            k = x[i] + k;
            while(a2 and x[i] == '7') { k = sete + k; a2--; }
        }
        while(a1) { k = quatro + k; a1--; }
        x = k;
        if(!a2) okx = true;
    }

    quatro = "4";
    sete = "7";

    a1 = b1; a2 = b2; a3 = b3; a4 = b4;
    a2--;
    string y = sete += gen('7');
    if(!a3 and !a4) {
        string k;
        for(int i = 0; i < y.size(); i++) {
            k = y[i] + k;
            while(a1 and y[i] == '4') { k = quatro + k; a1--; }
        }
        y = k;
        k = "";
        for(int i = y.size(); i >= 0; i--) {
            k = y[i] + k;
            while(a2 and y[i] == '7') { k = sete + k; a2--; }
        }
        while(a2) { y = sete += y; a2--; }
        if(!a1 and !a2) oky = true;
    }

    if(okx) cout << x << endl;
    else if(oky) cout << y << endl;
    else cout << -1 << endl;

    return 0;
}

