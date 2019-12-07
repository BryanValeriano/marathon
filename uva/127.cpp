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

vector<vector<string>> v;

bool merge(int pos, int dist) {
    if(pos-dist < 0) return 0;

    string ok = v[pos].back();
    string nok = v[pos-dist].back();

    if(ok[0] == nok[0] or ok[1] == nok[1]) {
        v[pos-dist].pb(ok);
        v[pos].pop_back();
        if(v[pos].size() == 0) v.erase(v.begin()+pos);
        return 1;
    }

    return 0;
}

void rev() {
    for(int i = 1; i < v.size(); i++) {
        if(merge(i,3)) i = 0; 
        else if(merge(i,1)) i = 0;   
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    string ok;
    cin >> ok;
    while(ok != "#") {
        v.pb(vector<string>(1,ok));

        for(int i = 1; i < 52; i++) {
            cin >> ok;
            v.pb(vector<string>(1,ok));
            if(merge(v.size()-1,3)) rev(); 
            else if(merge(v.size()-1,1)) rev();
        }

        cin >> ok;

        cout << v.size() << " pile" << (v.size() > 1? "s " : " ") << "remaining: ";
        for(int i = 0; i < v.size(); i++) cout << v[i].size() << (i + 1 < v.size()? " " : "");
        cout << endl;

        v.clear();
    }

    return 0;
}

