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

vector<string> at;
vector<string> cd;

vector<string> read(string x) {
    vector<string> tmp;
    string s = "";

    for(int i = 0; i < x.size(); i++) {
        if(x[i] == '/') tmp.pb(s), s = "";
        else s += x[i];
    }
    tmp.pb(s);
    return tmp;
}

void merge() {
    if(cd[0] == "") at.clear();

    for(int i = (cd[0] == ""); i < cd.size(); i++) {
        if(cd[i] == "..") at.pop_back();
        else at.pb(cd[i]);
    }
}

void print() {
    for(int i = 0; i < at.size(); i++) cout << "/" << at[i];
    cout << "/";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    string a,b;
    while(n--) {
        cin >> a;
        if(a == "pwd") print();
        else {
            cin >> b;
            cd = read(b);
            merge();
        }
    }



    return 0;
}

